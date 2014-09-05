#ifndef INTERACTIONOBJECT_H
#define INTERACTIONOBJECT_H
#include "AnimatedObject.h"

class InteractionObject : public AnimatedObject {
public:
	InteractionObject(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int nrOfFrames = 1,
	float changingSpeed = 100.0f) : AnimatedObject(texture, position, textureRect, nrOfFrames, changingSpeed) {}
	~InteractionObject() {}
	virtual void interact() = 0;
};

#endif // INTERACTIONOBJECT_H