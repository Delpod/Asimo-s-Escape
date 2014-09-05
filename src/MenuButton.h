#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include "GameObject.h"

class MenuButton : public GameObject {
public:
	MenuButton(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int callbackId = 0);
	int getCallbackId();
	void changeState(int change = 0);
	std::string type() { return std::string("MenuButton"); }
protected:
	int m_callbackId;
};

#endif // MENUBUTTON_H