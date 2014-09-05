#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect) : body(nullptr),
deadly(false) {
	m_pSprite.setTexture(texture);
	m_pSprite.setPosition(position);
	m_pSprite.setTextureRect(textureRect);
	m_textureRect = textureRect;
}

sf::Sprite* GameObject::getSprite() {
	return &m_pSprite;
}

void GameObject::setTextureRect(sf::IntRect &textureRect) {
	m_pSprite.setTextureRect(textureRect);
}

void GameObject::createCollidable() {
	bodyDef = new b2BodyDef();
	bodyDef->fixedRotation = true;
	bodyDef->position.Set(m_pSprite.getPosition().x / 32.0f, m_pSprite.getPosition().y / 32.0f);
	
	body = Game::Instance()->getWorld()->CreateBody(bodyDef);
	
	b2PolygonShape box;
	box.SetAsBox(m_pSprite.getLocalBounds().width / 64.0f, m_pSprite.getLocalBounds().height / 64.0f, b2Vec2(0.0f, 0.0f), 0.0f);
	body->CreateFixture(&box, 0.0f);
	
	m_pSprite.setPosition(body->GetPosition().x * 32.0f, body->GetPosition().y * 32.0f);
}