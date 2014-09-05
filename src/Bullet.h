#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"

class Bullet : public GameObject {
public:
	Bullet(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, b2Vec2 speedVec) : GameObject(texture, position, textureRect), m_speedVec(speedVec) { deadly = true; createCollidable(); }
	~Bullet() { }
	std::string type() { return std::string("Bullet"); }
	void update(sf::Time &pauseTime) {
		m_pSprite.setPosition(body->GetPosition().x * 32.0f, body->GetPosition().y * 32.0f);
		body->SetLinearVelocity(m_speedVec);
	}
	void createCollidable();
private:
	b2Vec2 m_speedVec;
};

#endif // BULLET_H