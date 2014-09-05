#include "Box.h"
#include "Game.h"

void Box::createCollidable() {
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->fixedRotation = true;
	bodyDef->position.Set(m_pSprite.getPosition().x / 32.0f, m_pSprite.getPosition().y / 32.0f);

	body = Game::Instance()->getWorld()->CreateBody(bodyDef);
	
	b2MassData massData;
	massData.mass = 20.0f;
	body->SetMassData(&massData);
	
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(m_pSprite.getLocalBounds().width / 64.0f, m_pSprite.getLocalBounds().height / 64.0f, b2Vec2(0.15f, 0.11f), 0.0f);
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 44.3f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.05f;
	
	body->CreateFixture(&fixtureDef);
}