#include "Bullet.h"
#include "Game.h"

void Bullet::createCollidable() {
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->fixedRotation = true;
	bodyDef->bullet = true;
	bodyDef->position.Set(m_pSprite.getPosition().x / 32.0f, m_pSprite.getPosition().y / 32.0f);
	
	body = Game::Instance()->getWorld()->CreateBody(bodyDef);
	
	b2PolygonShape box;
	box.SetAsBox(m_pSprite.getLocalBounds().width / 64.0f, m_pSprite.getLocalBounds().height / 64.0f, b2Vec2(0.0f, 0.0f), 0.0f);
	body->CreateFixture(&box, 0.0f);
	
	m_pSprite.setPosition(body->GetPosition().x * 32.0f, body->GetPosition().y * 32.0f);
}