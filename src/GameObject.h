#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect);
	virtual ~GameObject() { delete bodyDef; body->GetWorld()->DestroyBody(body); }
	sf::Sprite* getSprite();
	virtual void update(sf::Time &pauseTime) {}
	void setTextureRect(sf::IntRect &textureRect);
	virtual std::string type() { return std::string("GameObject"); }
	virtual void createCollidable();
	const b2AABB& getAABB() { return body->GetFixtureList()->GetAABB(0); }
	bool isDeadly() { return deadly; }
	const b2Body* getBody() { return body; }
protected:
	sf::Sprite m_pSprite;
	sf::IntRect m_textureRect;
	b2BodyDef* bodyDef;
	b2Body* body;
	bool deadly;
};

#endif // GAMEOBJECT_H