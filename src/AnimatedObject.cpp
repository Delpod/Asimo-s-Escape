#include "AnimatedObject.h"

AnimatedObject::AnimatedObject(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int nrOfFrames,
float changingSpeed) : GameObject(texture, position, textureRect),
	m_animationTriggered(false),
	m_nrOfFrames(nrOfFrames),
	m_currFrame(0),
	m_changingSpeed(changingSpeed),
	m_pTextureRect(textureRect),
	m_counter(sf::seconds(0.0f)) {
}

void AnimatedObject::update(sf::Time &pauseTime) {
	if(m_animationTriggered) {
		m_counter += sf::seconds(m_clock.restart().asSeconds() - pauseTime.asSeconds());
		if(m_counter.asMilliseconds() > m_changingSpeed) {
			m_counter -= sf::milliseconds(m_changingSpeed);
			if(m_currFrame == m_nrOfFrames) {
				m_currFrame = 0;
				m_animationTriggered = false;
			}
			++m_currFrame;
			m_pSprite.setTextureRect(sf::IntRect(m_textureRect.width * (m_currFrame-1), 0, m_textureRect.width, m_textureRect.height));
		}
	}
}