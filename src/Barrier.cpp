#include "Barrier.h"
#include "Game.h"
void Barrier::update(sf::Time& pauseTime) {
	if(m_animationTriggered) {
		body->SetLinearVelocity(b2Vec2(-4.0f, 0.0f));
		if(body->GetPosition().x + 2.0f < startingPos.x) {
			body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
			m_animationTriggered = false;
		}
		m_pSprite.setPosition(body->GetPosition().x * 32.0f, body->GetPosition().y * 32.0f);
	}
}

void Barrier::createCollidable() {
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_kinematicBody;
	bodyDef->fixedRotation = true;
	bodyDef->position.Set(m_pSprite.getPosition().x / 32.0f, m_pSprite.getPosition().y / 32.0f);
	
	body = Game::Instance()->getWorld()->CreateBody(bodyDef);
	
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(m_pSprite.getLocalBounds().width / 64.0f, m_pSprite.getLocalBounds().height / 64.0f, b2Vec2(0.0f, -0.45f), 0.0f);
	
	body->CreateFixture(&dynamicBox, 0.0f);
	startingPos = body->GetPosition();
}