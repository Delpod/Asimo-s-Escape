#include "Player.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>
Player::Player(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int nrOfFrames,
float changingSpeed) : AnimatedObject(texture, position, textureRect, nrOfFrames, changingSpeed),
	m_walkingTextureRect(0, 0, 15, 43),
	m_standingTextureRect(0, 0, 15, 43),
	m_beginRunTextureRect(0, 0, 16, 43),
	m_endRunTextureRect(0, 0, 16, 43),
	m_walkInTextureRect(0, 0, 15, 43),
	m_nrOfFramesWalking(4),
	m_nrOfFramesStanding(4),
	m_nrOfFramesBeginRun(2),
	m_nrOfFramesEndRun(2),
	m_nrOfFramesWalkIn(5),
	m_changingSpeedWalking(150),
	m_changingSpeedStanding(150),
	m_changingSpeedBeginRun(90),
	m_changingSpeedEndRun(90),
	m_changingSpeedWalkIn(75),
	m_speed(0.12f),
	player_state(STANDING) {
	TextureManager::Instance()->load("data/gfx/run.png", "run");
	TextureManager::Instance()->load("data/gfx/beginrun.png", "beginrun");
	TextureManager::Instance()->load("data/gfx/endrun.png", "endrun");
	TextureManager::Instance()->load("data/gfx/walkin.png", "walkin");
	m_walkingTexture = TextureManager::Instance()->getTexture("run");
	m_standingTexture = TextureManager::Instance()->getTexture("run");
	m_beginRunTexture = TextureManager::Instance()->getTexture("beginrun");
	m_endRunTexture = TextureManager::Instance()->getTexture("endrun");
	m_walkInTexture = TextureManager::Instance()->getTexture("walkin");
	m_nrOfFrames = m_nrOfFramesStanding;
	deadly = false;
	m_time = m_time.Zero;
	m_clock.restart();
	m_changingSpeed = m_changingSpeedStanding;
}

void Player::update(sf::Time &pauseTime) {
	b2Vec2 linearVelocity;
	if(player_state != WALKIN)
		linearVelocity = body->GetLinearVelocity();
	if(player_state == WALKIN) {
		if(m_currFrame == m_nrOfFrames) {
			Game::Instance()->markNextGameState();
			return;
		}
		m_time += sf::milliseconds(m_clock.restart().asMilliseconds() - pauseTime.asMilliseconds());
		if(m_time.asMilliseconds() > m_changingSpeed) {
			m_time -= sf::milliseconds(m_changingSpeed);
			m_pSprite.setTextureRect(sf::IntRect(m_textureRect.width * (m_currFrame++), 0, m_textureRect.width, m_textureRect.height));
		}
		
	} else if(((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			|| (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
				&& (!(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				|| !(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))) {
		if(player_state == STANDING || player_state == ENDRUN) {
			m_clock.restart();
			m_time = m_time.Zero;
			player_state = BEGINRUN;
			m_currFrame = 0;
			m_nrOfFrames = m_nrOfFramesBeginRun;
			m_changingSpeed = m_changingSpeedBeginRun;
			m_textureRect = m_beginRunTextureRect;
			m_pSprite.setTexture(*m_beginRunTexture);
			m_pSprite.setTextureRect(m_textureRect);
		}
		if(m_currFrame == m_nrOfFrames) {
			m_currFrame = 0;
			if(player_state == BEGINRUN) {
				player_state = WALKING;
				m_nrOfFrames = m_nrOfFramesWalking;
				m_changingSpeed = m_changingSpeedWalking;
				m_textureRect = m_walkingTextureRect;
				m_pSprite.setTexture(*m_walkingTexture);
				m_pSprite.setTextureRect(m_textureRect);
			}
		}
		m_time += sf::milliseconds(m_clock.restart().asMilliseconds() - pauseTime.asMilliseconds());
		if(m_time.asMilliseconds() > m_changingSpeed) {
			m_time -= sf::milliseconds(m_changingSpeed);
			m_pSprite.setTextureRect(sf::IntRect(m_textureRect.width * (m_currFrame++), 0, m_textureRect.width, m_textureRect.height));
		}
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) {
			body->SetLinearVelocity(b2Vec2(-5.0f, linearVelocity.y));
			if(m_pSprite.getScale().x != 1.0f) {
				m_pSprite.setScale(1.0f, 1.0f);
				m_pSprite.setOrigin(0.0f, 0.0f);
			}
		} else if((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) {
			body->SetLinearVelocity(b2Vec2(5.0f, linearVelocity.y));
			if(m_pSprite.getScale().x != -1.0f) {
				m_pSprite.setScale(-1.0f, 1.0f);
				m_pSprite.setOrigin(m_pSprite.getLocalBounds().width, 0.0f);
			}
		}
	} else {
		body->SetLinearVelocity(b2Vec2(0.0f, linearVelocity.y));
		if(player_state == WALKING || player_state == BEGINRUN) {
			m_clock.restart();
			m_time = m_time.Zero;
			player_state = ENDRUN;
			m_currFrame = 0;
			m_nrOfFrames = m_nrOfFramesEndRun;
			m_changingSpeed = m_changingSpeedEndRun;
			m_textureRect = m_endRunTextureRect;
			m_pSprite.setTexture(*m_endRunTexture);
			m_pSprite.setTextureRect(m_textureRect);
		}
		if(m_currFrame == m_nrOfFrames) {
			m_currFrame = 0;
			if(player_state == ENDRUN) {
				player_state = STANDING;
				m_nrOfFrames = m_nrOfFramesStanding;
				m_changingSpeed = m_changingSpeedStanding;
				m_textureRect = m_standingTextureRect;
				m_pSprite.setTexture(*m_standingTexture);
				m_pSprite.setTextureRect(m_textureRect);
			}
		}
		m_time += sf::milliseconds(m_clock.restart().asMilliseconds() - pauseTime.asMilliseconds());
		if(m_time.asMilliseconds() > m_changingSpeed) {
			m_time -= sf::milliseconds(m_changingSpeed);
			m_pSprite.setTextureRect(sf::IntRect(m_textureRect.width * (m_currFrame++), 0, m_textureRect.width, m_textureRect.height));
		}
	}
	if(player_state != WALKIN)
		m_pSprite.setPosition(body->GetPosition().x * 32.0f, body->GetPosition().y * 32.0f);
}

void Player::createCollidable() {
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->fixedRotation = true;
	bodyDef->position.Set(m_pSprite.getPosition().x / 32.0f, m_pSprite.getPosition().y / 32.0f);

	body = Game::Instance()->getWorld()->CreateBody(bodyDef);
	
	b2MassData massData;
	massData.mass = 70.0f;
	body->SetMassData(&massData);
	
		b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(m_pSprite.getLocalBounds().width / 64.0f, m_pSprite.getLocalBounds().height / 64.0f, b2Vec2(-0.24f, 0.11f), 0.0f);
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 88.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.05f;
	
	body->CreateFixture(&fixtureDef);
}

void Player::walkIn() {
	if(player_state == WALKIN)
		return;
	m_time = m_time.Zero;
	player_state = WALKIN;
	m_currFrame = 0;
	m_nrOfFrames = m_nrOfFramesWalkIn;
	m_changingSpeed = m_changingSpeedWalkIn;
	m_textureRect = m_walkInTextureRect;
	m_pSprite.setTexture(*m_walkInTexture);
	m_pSprite.setTextureRect(m_walkInTextureRect);
	Game::Instance()->playWalkIn();
}