#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H
#include "GameObject.h"

class AnimatedObject : public GameObject {
public:
	AnimatedObject(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int nrOfFrames,
	float changingSpeed);
	virtual void update(sf::Time &pauseTime);
	virtual void triggerAnimation() {
		m_clock.restart();
		m_animationTriggered =  true;
	}
	std::string type() { return std::string("AnimatedObject"); }
protected:
	bool m_animationTriggered;
	int m_nrOfFrames;
	int m_currFrame;
	float m_changingSpeed;
	sf::IntRect m_pTextureRect;
	sf::Clock m_clock;
	sf::Time m_counter;
};

#endif // ANIMATEDOBJECT_H