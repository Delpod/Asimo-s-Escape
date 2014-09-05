#ifndef BOX_H
#define BOX_H
#include "GameObject.h"

class Box : public GameObject {
public:
	Box(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect) : GameObject(texture, sf::Vector2f(position.x, position.y - 10), textureRect) {}
	~Box() {}
	void update(sf::Time &pauseTime) { m_pSprite.setPosition(body->GetPosition().x * 32.0f, body->GetPosition().y * 32.0f); }
	std::string type() { return std::string("Box"); }
	void createCollidable();
};

#endif // BOX_H