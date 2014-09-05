#include "Lever.h"

void Lever::update(sf::Time& pauseTime) {
	AnimatedObject::update(pauseTime);
	if(m_canTrigger == false && m_animationTriggered == false) {
		m_pSprite.setTextureRect(sf::IntRect(m_textureRect.width * (m_nrOfFrames - 1), 0, m_textureRect.width, m_textureRect.height));
	}
}