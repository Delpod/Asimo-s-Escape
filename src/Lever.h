#ifndef LEVER_H
#define LEVER_H
#include "InteractionObject.h"
#include "Game.h"
#include <iostream>
class Lever : public InteractionObject {
public:
	Lever(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, std::string barrierID) : InteractionObject(texture, position, textureRect, 5, 50.0f), m_barrierID(barrierID), m_canTrigger(true) {}
	~Lever() {}
	void interact() {
		if(m_canTrigger) {
			(*Game::Instance()->getLevel()->getBarrierMap())[m_barrierID]->triggerAnimation();
			triggerAnimation();
			Game::Instance()->playLever();
			m_canTrigger = false;
		}
	}
	std::string type() { return std::string("Lever"); }
	void update(sf::Time& pauseTime);
private:
	std::string m_barrierID;
	bool m_canTrigger;
};

#endif // LEVER_H