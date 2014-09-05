#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>
#include <map>
#include "Layer.h"
#include "Player.h"
#include "Barrier.h"
#include "TextureManager.h"

class Level {
public:
	~Level();
	
	void update(sf::Time &m_pauseTime);
	void draw(sf::RenderWindow *pWindow);
	
	std::vector<Layer*>* getObjectLayers() { return &m_objectLayers; }
	std::vector<Layer*>* getTileLayers() { return &m_tileLayers; }
	std::vector<Layer*>* getCollisionLayers() { return &m_collisionLayers; }
	const std::vector<Layer*>& getCollidableLayers() { return m_collisionLayers; }
	std::vector<Layer*>* getInteractionLayers() { return &m_interactionLayers; }
	const std::vector<Layer*>& getInteractiveLayers() { return m_interactionLayers; }
	Layer* getBulletLayer() { return &m_bulletLayer; }
	sf::Texture* getTileset() { return m_tileset; }
	GameObject* getInteractionObject() { return m_pInteraction; }
	std::map<std::string, Barrier*>* getBarrierMap() { return &m_barrierMap; }
	
	void setMapWidth(int mapWidth);
	Player* getPlayer() { return m_pPlayer; }
	void setPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }
private:
	Level() : m_wKey(*TextureManager::Instance()->getTexture("wKey"), sf::Vector2f(0.0f, 0.0f), sf::IntRect(0, 0, 32, 32)), m_pInteraction(nullptr) {m_wKey.getSprite()->setOrigin(16.0f, 16.0f);}
	bool checkPlayerOverlap();
	GameObject* checkPlayerInteraction();
	void checkEnemyCrushing();
	void checkBulletOverlap();
	float distance(sf::Vector2f pt1, sf::Vector2f pt2);
	friend class LevelParser;
	
	std::vector<Layer*> m_objectLayers;
	std::vector<Layer*> m_tileLayers;
	std::vector<Layer*> m_collisionLayers;
	std::vector<Layer*> m_interactionLayers;
	std::map<std::string, Barrier*> m_barrierMap;
	GameObject m_wKey;
	Layer m_bulletLayer;
	sf::Texture* m_tileset;
	
	GameObject* m_pInteraction;
	
	Player* m_pPlayer;
};

#endif // LEVEL_H