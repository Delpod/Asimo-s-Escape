#include "Layer.h"

Layer::~Layer() {
	for(std::vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it) {
		delete (*it);
	}
	m_gameObjects.clear();
}

void Layer::update(sf::Time &pauseTime) {
	for(unsigned int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->update(pauseTime);
	}
}

void Layer::draw(sf::RenderWindow *pWindow) {
	for(unsigned int i = 0; i < m_gameObjects.size(); ++i) {
		pWindow->draw(*(m_gameObjects[i]->getSprite()));
	}
}