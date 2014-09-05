#ifndef BARRIER_H
#define BARRIER_H
#include "AnimatedObject.h"

class Barrier : public AnimatedObject {
public:
	Barrier(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect) : AnimatedObject(texture, position, textureRect, 1, 0.0f) {}
	~Barrier() {}
	void update(sf::Time& pauseTime);
	std::string type() { return std::string("Barrier"); }
	void triggerAnimation() { m_animationTriggered = true; }
private:
	void createCollidable();
	b2Vec2 startingPos;
};

#endif // BARRIER_H