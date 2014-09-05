#ifndef PLAYER_H
#define PLAYER_H
#include "AnimatedObject.h"

class Player : public AnimatedObject {
public:
	Player(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int nrOfFrames,
		float changingSpeed);
	~Player() {}
	void update(sf::Time &pauseTime);
	std::string type() { return std::string("Player"); }
	void createCollidable();
	void walkIn();
protected:
	sf::Clock m_clock;
	sf::Time m_time;
	sf::Texture* m_walkingTexture;
	sf::Texture* m_standingTexture;
	sf::Texture* m_beginRunTexture;
	sf::Texture* m_endRunTexture;
	sf::Texture* m_walkInTexture;
	sf::IntRect m_walkingTextureRect;
	sf::IntRect m_standingTextureRect;
	sf::IntRect m_beginRunTextureRect;
	sf::IntRect m_endRunTextureRect;
	sf::IntRect m_walkInTextureRect;
	int m_nrOfFramesWalking;
	int m_nrOfFramesStanding;
	int m_nrOfFramesBeginRun;
	int m_nrOfFramesEndRun;
	int m_nrOfFramesWalkIn;
	float m_changingSpeedWalking;
	float m_changingSpeedStanding;
	float m_changingSpeedBeginRun;
	float m_changingSpeedEndRun;
	float m_changingSpeedWalkIn;
	float m_speed;
	enum { WALKING, STANDING, BEGINRUN, ENDRUN, WALKIN } player_state;
};

#endif // PLAYER_H