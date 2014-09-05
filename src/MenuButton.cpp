#include "MenuButton.h"

MenuButton::MenuButton(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int callbackId) :
GameObject(texture, position, textureRect), m_callbackId(callbackId) {
}

int MenuButton::getCallbackId() {
	return m_callbackId;
} 

void MenuButton::changeState(int change) {
	m_pSprite.setTextureRect(sf::IntRect(m_textureRect.left + m_textureRect.width * change, 0, m_textureRect.width, m_textureRect.height));
}