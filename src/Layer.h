#ifndef LAYER_H
#define LAYER_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Layer {
public:
	~Layer();
	void draw(sf::RenderWindow *pWindow);
	void update(sf::Time &pauseTime);
	
	void setMapWidth(int mapWidth) { m_mapWidth = mapWidth; }
	std::vector<GameObject*>* getGameObjects() {
		return &m_gameObjects;
	}
protected:
	int m_mapWidth;
	std::vector<GameObject*> m_gameObjects;
};

#endif // LAYER_H