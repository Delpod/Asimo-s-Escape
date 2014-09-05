#include "Enemy.h"
#include <cmath>
#include <iostream>
#include "Game.h"
#include "RayCastAnyCallback.h"
#include "Bullet.h"

Enemy::Enemy(sf::Texture &texture, sf::Texture &texture2, sf::Vector2f position, float speed, float waitingTime,
float begin, float end, bool standing, bool lookingSide) : AnimatedObject(texture, position, sf::IntRect(0, 0, 29, 55), 8, 0.1f),
	m_texture(texture),
	m_texture2(texture2),
	m_textureRect2(0, 0, 20, 55),
	m_physicsRect(0, 5, 20, 50),
	m_physicsRect2(0, 5, 20, 50),
	m_physicsRect_inv(9, 5, 20, 50),
	m_physicsRect2_inv(0, 5, 20, 50),
	m_counter2(sf::seconds(0.0f)),
	m_shootingCounter(sf::seconds(0.0f)),
	m_nrOfFrames2(1),
	m_changingSpeed2(0.1f),
	m_speed(speed),
	m_waitingTime(waitingTime),
	m_begin(begin),
	m_end(end),
	m_bWalking(true),
	m_bStanding(standing),
	m_sSide(lookingSide),
	side(0) {
	deadly = true;
	if(standing) {
		m_pSprite.setTexture(m_texture2);
		m_pSprite.setTextureRect(m_textureRect2);

		m_pSprite.setScale(m_sSide == 1 ? 1.0f : -1.0f, 1.0f);
		m_pSprite.setOrigin(std::fabs(m_pSprite.getOrigin().x - m_pSprite.getLocalBounds().width), 0.0f);
	}
}

void Enemy::update(sf::Time &pauseTime) {
	bool stopped = false, doRaycast = false, shootingState = false, shooting = false;;
	if(side != 1) {
		if(Game::Instance()->getLevel()->getPlayer()->getSprite()->getPosition().x < m_pSprite.getPosition().x) 
			doRaycast = true;
	} else {
		if(Game::Instance()->getLevel()->getPlayer()->getSprite()->getPosition().x > m_pSprite.getPosition().x) 
			doRaycast = true;
	}
	if(doRaycast) {
		RayCastAnyCallback callback;
		b2Vec2 point1 = b2Vec2((m_pSprite.getGlobalBounds().left - 10) / 32.0f , (m_pSprite.getGlobalBounds().top + m_pSprite.getGlobalBounds().height / 2.0f) / 32.0f) ;
		b2Vec2 point2 = b2Vec2(side != 1 ? 0.0f : 100.0f, body->GetPosition().y);
		body->GetWorld()->RayCast(&callback, point1, point2);
		if(callback.m_hit && callback.m_body == Game::Instance()->getLevel()->getPlayer()->getBody()) {
			m_shootingCounter = sf::milliseconds(m_shootingCounter.asMilliseconds() - m_shootingClock.restart().asMilliseconds());
			shootingState = true;
			if(m_shootingCounter.asSeconds() <= 0.0f) {
				m_bWalking = false;
				shooting = true;
				m_shootingCounter = sf::seconds(0.2f);
				m_clock.restart();
				m_currFrame = 1;
				m_pSprite.setTexture(m_texture2);
				m_pSprite.setTextureRect(m_textureRect2);
				m_counter2 = m_counter.Zero;
				body->DestroyFixture(body->GetFixtureList());
				if(side != 2)
					createFixture(m_physicsRect2);
				else
					createFixture(m_physicsRect2_inv);
			}
		}
	}
	if(shootingState) {
		if(shooting) {
			Layer* bulletLayer = Game::Instance()->getLevel()->getBulletLayer();
			TextureManager::Instance()->load("data/gfx/bullet.png", "bullet");
			Bullet* gameObject = new Bullet(*TextureManager::Instance()->getTexture("bullet"), sf::Vector2f(m_pSprite.getGlobalBounds().left - 15,
								m_pSprite.getGlobalBounds().top + m_pSprite.getGlobalBounds().height / 2.0f), sf::IntRect(0, 0, 4, 4), b2Vec2(side != 1 ? -25.0f : 25.0f, 0.0f));
			bulletLayer->getGameObjects()->push_back(gameObject);
			Game::Instance()->playShoot();
			body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
		}
	} else if(m_bWalking && !m_bStanding) {
		m_shootingClock.restart();
		if((body->GetPosition().x > m_end / 32.0f && side != 2) || (body->GetPosition().x < m_begin / 32.0f && side != 1)) {
			m_bWalking = false;
			stopped = true;
			m_currFrame = 1;
			m_speed = -m_speed;
			m_pSprite.setTexture(m_texture2);
			m_pSprite.setTextureRect(m_textureRect2);
			m_counter2 = m_counter.Zero;
			body->DestroyFixture(body->GetFixtureList());
			if(side != 2)
				createFixture(m_physicsRect2);
			else
				createFixture(m_physicsRect2_inv);
		}
		if(!stopped) {
			body->SetLinearVelocity(b2Vec2(m_speed, 0.0f));
			m_counter += sf::milliseconds(m_clock.restart().asMilliseconds() - pauseTime.asMilliseconds());
			if(m_counter.asMilliseconds() > m_changingSpeed) {
				m_counter -= sf::seconds(m_changingSpeed);
				if(m_currFrame == m_nrOfFrames) {
					m_currFrame = 0;
				}
				m_pSprite.setTextureRect(sf::IntRect(m_textureRect.width * (m_currFrame++), 0, m_textureRect.width, m_textureRect.height));
			}
		}
	} 
	if(!m_bWalking && !m_bStanding) {
		m_counter2 += sf::seconds(m_clock.restart().asSeconds());
		body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
		if(m_counter2.asMilliseconds() > m_waitingTime) {
			m_bWalking = true;
			m_counter = sf::seconds(0.0f);
			m_pSprite.setTexture(m_texture);
			m_pSprite.setTextureRect(m_textureRect);
			

			body->DestroyFixture(body->GetFixtureList());
			side = body->GetPosition().x > m_end / 32.0f ? 2 : 1;
			if(side != 2)
				createFixture(m_physicsRect);
			else
				createFixture(m_physicsRect_inv);
			m_pSprite.setScale(-1.0f * m_pSprite.getScale().x, 1.0f);
			m_pSprite.setOrigin(std::fabs(m_pSprite.getOrigin().x - m_pSprite.getLocalBounds().width), 0.0f);
		}
	}
	m_pSprite.setPosition(body->GetPosition().x * 32.0f, body->GetPosition().y * 32.0f);
}

void Enemy::createCollidable() {
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->fixedRotation = true;
	bodyDef->position.Set(m_pSprite.getPosition().x / 32.0f, m_pSprite.getPosition().y / 32.0f);

	body = Game::Instance()->getWorld()->CreateBody(bodyDef);
	
	b2MassData massData;
	massData.mass = 100.0f;
	body->SetMassData(&massData);
	
	createFixture(m_physicsRect);
}

void Enemy::createFixture(sf::IntRect& intRect) {
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(intRect.width / 64.0f, intRect.height / 64.0f, b2Vec2(intRect.left / 32.0f, intRect.top / 160.0f + 0.35f), 0.0f);
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 93.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.1f;
	
	body->CreateFixture(&fixtureDef);
}