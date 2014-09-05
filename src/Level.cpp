#include "Level.h"
#include "Game.h"

Level::~Level() {
	for(unsigned int i = 0; i < m_tileLayers.size(); ++i) {
		delete m_tileLayers[i];
	}
	m_tileLayers.clear();
	for(unsigned int i = 0; i < m_objectLayers.size(); ++i) {
		delete m_objectLayers[i];
	}
	m_objectLayers.clear();
}

void Level::update(sf::Time &pauseTime) {
	m_pInteraction = checkPlayerInteraction();
	m_bulletLayer.update(pauseTime);
	checkEnemyCrushing();
	if(checkPlayerOverlap()) {
		Game::Instance()->unmarkNextGameState();
		Game::Instance()->initLoseMenuState();
	} else {
		checkBulletOverlap();
	}
	for(unsigned int i = 0; i < m_tileLayers.size(); ++i) {
		m_tileLayers[i]->update(pauseTime);
	}
	for(unsigned int i = 0; i < m_objectLayers.size(); ++i) {
		if(Game::Instance()->getState() == 2)
			m_objectLayers[i]->update(pauseTime);
	}
}

void Level::draw(sf::RenderWindow *pWindow) {
	for(unsigned int i = 0; i < m_tileLayers.size(); ++i) {
		m_tileLayers[i]->draw(pWindow);
	}
	for(unsigned int i = 0; i < m_objectLayers.size(); ++i) {
		m_objectLayers[i]->draw(pWindow);
	}
	m_bulletLayer.draw(pWindow);
	if(m_pInteraction != nullptr)
		pWindow->draw(*m_wKey.getSprite());
}

void Level::setMapWidth(int mapWidth) {
	for(unsigned int i = 0; i < m_tileLayers.size(); ++i) {
		m_tileLayers[i]->setMapWidth(mapWidth);
	}
	for(unsigned int i = 0; i < m_objectLayers.size(); ++i) {
		m_objectLayers[i]->setMapWidth(mapWidth);
	}
}

bool Level::checkPlayerOverlap() {
	bool overlap = false;
	for(unsigned int i = 0; i < m_collisionLayers.size(); ++i) {
		for(unsigned int j = 0; j < m_collisionLayers.size(); ++j) {
			for(unsigned int k = 0; k < m_collisionLayers[i]->getGameObjects()->size(); ++k) {
					GameObject *gameObject = (*(m_collisionLayers[i]->getGameObjects()))[k];
					if(gameObject->isDeadly()) {
						const b2AABB &aabb = gameObject->getAABB();
						if(b2TestOverlap(m_pPlayer->getAABB(), aabb)) {
							overlap = true;
						}
					}
			}
		}
	}
	
	for(unsigned int i = 0; i < m_bulletLayer.getGameObjects()->size(); ++i) {
		GameObject *gameObject = (*m_bulletLayer.getGameObjects())[i];
		const b2AABB &aabb = gameObject->getAABB();
		
		if(b2TestOverlap(m_pPlayer->getAABB(), aabb)) {
			overlap = true;
		}
	}
	return overlap;
}

GameObject* Level::checkPlayerInteraction() {
	for(unsigned int i = 0; i < m_interactionLayers.size(); ++i) {
		for(unsigned int j = 0; j < m_interactionLayers.size(); ++j) {
			for(unsigned int k = 0; k < m_interactionLayers[i]->getGameObjects()->size(); ++k) {
					if(m_pPlayer->getBody()->GetLinearVelocity().y > 0.1f)
						return nullptr;
					GameObject *gameObject = (*(m_interactionLayers[i]->getGameObjects()))[k];
					
					sf::Vector2f size1(m_pPlayer->getSprite()->getLocalBounds().width / 2.0f, m_pPlayer->getSprite()->getLocalBounds().height / 2.0f);
					sf::Vector2f size2(gameObject->getSprite()->getLocalBounds().width / 2.0f, gameObject->getSprite()->getLocalBounds().height / 2.0f);
					
					sf::Vector2f pos1(m_pPlayer->getSprite()->getPosition().x + size1.x, m_pPlayer->getSprite()->getPosition().y + size1.y);
					sf::Vector2f pos2(gameObject->getSprite()->getPosition().x + size2.x, gameObject->getSprite()->getPosition().y + size2.y);
					
					float radius1 = 0.4f * sqrt(size1.x * size1.x + size1.y * size1.y);
					float radius2 = 0.4f * sqrt(size2.x * size2.x + size2.y * size2.y);
					
					if(distance(pos1, pos2) < radius1 + radius2) {
						if(gameObject != m_pInteraction)
							m_wKey.getSprite()->setPosition(gameObject->getSprite()->getPosition().x + gameObject->getSprite()->getLocalBounds().width / 2.0f, gameObject->getSprite()->getPosition().y - 40);
						return gameObject;
					}
			}
		}
	}
	return nullptr;
}

float Level::distance(sf::Vector2f pt1, sf::Vector2f pt2) {
	sf::Vector2f tmp(pt1.x - pt2.x, pt1.y - pt2.y);

	return sqrt(tmp.x * tmp.x + tmp.y * tmp.y);
}

void Level::checkEnemyCrushing() {
	for(unsigned int i = 0; i < m_collisionLayers.size(); ++i) {
		std::vector<GameObject*>::iterator it;
		for(unsigned int j = 0; j < m_collisionLayers.size(); ++j) {
			std::vector<GameObject*>::iterator it2;
			it = m_collisionLayers[i]->getGameObjects()->begin();
			for(unsigned int k = 0; k < m_collisionLayers[i]->getGameObjects()->size(); ++k, ++it) {
				it2 = m_collisionLayers[j]->getGameObjects()->begin();
				for(unsigned int l = 0; l < m_collisionLayers[j]->getGameObjects()->size(); ++l, ++it2) {
					GameObject* gameObject1 = (*m_collisionLayers[i]->getGameObjects())[k];
					GameObject* gameObject2 = (*m_collisionLayers[j]->getGameObjects())[l];
					if(((gameObject1->type() == std::string("Enemy") && gameObject2->type() == std::string("Box")) ||
						(gameObject1->type() == std::string("Box") && gameObject2->type() == std::string("Enemy"))) &&
						b2TestOverlap(gameObject1->getAABB(), gameObject2->getAABB())) {
						if(gameObject1->type() == std::string("Enemy")) {
							delete gameObject1;
							m_collisionLayers[i]->getGameObjects()->erase(it);
							Game::Instance()->playCrush();
							return;
						} else if(gameObject1->type() == std::string("Box")) {
							delete gameObject2;
							m_collisionLayers[j]->getGameObjects()->erase(it2);
							Game::Instance()->playCrush();
							return;
						}
					}
				}
			}
		}
	}
}

void Level::checkBulletOverlap() {
	std::vector<GameObject*>::iterator it;
	for(unsigned int i = 0; i < m_collisionLayers.size(); ++i) {
		it = m_bulletLayer.getGameObjects()->begin();
		for(unsigned int j = 0; j < m_bulletLayer.getGameObjects()->size(); ++j) {
			for(unsigned int k = 0; k < m_collisionLayers[i]->getGameObjects()->size(); ++k) {
				GameObject *bullet = (*m_bulletLayer.getGameObjects())[j];
				const b2AABB &aabb = bullet->getAABB();
				
				if((*m_collisionLayers[i]->getGameObjects())[k]->type() != std::string("Enemy") &&
					b2TestOverlap((*m_collisionLayers[i]->getGameObjects())[k]->getAABB(), aabb)) {
					delete (*m_bulletLayer.getGameObjects())[j];
					m_bulletLayer.getGameObjects()->erase(it);
					break;
				}
			}
			++it;
		}
	}
}