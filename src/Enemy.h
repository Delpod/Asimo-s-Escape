#ifndef ENEMY_H
#define ENEMY_H
#include "AnimatedObject.h"

class Enemy : public AnimatedObject {
public:
	Enemy(sf::Texture &texture, sf::Texture &texture2, sf::Vector2f position, float speed, float waitingTime,
	float begin, float end, bool standing, bool lookingSide);
	void update(sf::Time &pauseTime);
	std::string type() { return std::string("Enemy"); }
	void createCollidable();
protected:
	void createFixture(sf::IntRect& intRect);
	sf::Texture& m_texture;
	sf::Texture& m_texture2;
	sf::IntRect m_textureRect2;
	sf::IntRect m_physicsRect;
	sf::IntRect m_physicsRect2;
	sf::IntRect m_physicsRect_inv;
	sf::IntRect m_physicsRect2_inv;
	sf::Time m_counter2;
	sf::Clock m_shootingClock;
	sf::Time m_shootingCounter;
	int m_nrOfFrames2;
	float m_changingSpeed2;
	float m_speed;
	float m_waitingTime;
	float m_begin;
	float m_end;
	bool m_bWalking;
	bool m_bStanding;
	bool m_sSide;
	int side;
	
};

#endif // ENEMY_H