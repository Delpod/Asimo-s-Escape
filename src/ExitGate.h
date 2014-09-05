#ifndef EXITGATE_H
#define EXITGATE_H
#include "InteractionObject.h"
#include "Game.h"
class ExitGate : public InteractionObject {
public:
	ExitGate(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect) : InteractionObject(texture, position, textureRect) {}
	~ExitGate() {}
	void interact() { Game::Instance()->getLevel()->getPlayer()->walkIn(); }
	std::string type() { return std::string("ExitGate"); }
};

#endif // EXITGATE_H