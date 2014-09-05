#ifndef GAME_H
#define GAME_H
#include <Box2D/Box2D.h>
#include <SFML/Audio.hpp>
#include "GameObject.h"
#include "MenuButton.h"
#include "Level.h"
#include "TextureManager.h"

class Level;
class Player;

class Game {
public:
	static Game* Instance() {
		if(s_pInstance == nullptr) {
			s_pInstance = new Game();
		}
		return s_pInstance;
	}
	
	void init(sf::VideoMode vm, const char* name, int styles = 0);
	void handleEvents();
	void update();
	void draw();
	void clean();
	void quit() { m_bRunning = false; }
	bool isRunning() { return m_bRunning; }
	void clearMenuObjects() {
		m_menuObjects.clear();
		m_menuButtons.clear();
	}

	void initLoseMenuState();
	void markNextGameState() { m_bMarkToChangeLevel = true; }
	void unmarkNextGameState() { m_bMarkToChangeLevel = false; }
	
	b2World* getWorld() { return m_pWorld; }
	Level* getLevel() { return m_pLevel; }
	int getState() { return state; }
	
	void playWalkIn() {
		m_sound.setBuffer(m_walkInBuffer);
		m_sound.play();
	}
	void playShoot() {
		m_sound.setBuffer(m_shootBuffer);
		m_sound.play();
	}
	void playCrush() {
		m_sound.setBuffer(m_crushBuffer);
		m_sound.play();
	}
	void playDead() {
		m_sound.setBuffer(m_deadBuffer);
		m_sound.play();
	}
	void playLever() {
		m_sound.setBuffer(m_leverBuffer);
		m_sound.play();
	}
	void playClick() {
		m_sound.setBuffer(m_clickBuffer);
		m_sound.play();
	}
	
	int m_gameWidth;
	int m_gameHeight;

	unsigned int m_currentLevel;
	bool m_bLevelComplete;
private:
	Game();
	void initMainMenuState();
	void initPauseMenuState();
	void initGameState();
	void initNextGameState();
	void initGameEnd();
	void initPreGame();
	void returnToGame();
	static Game* s_pInstance;
	sf::RenderWindow* m_pWindow;
	sf::Music m_music;
	sf::SoundBuffer m_crushBuffer;
	sf::SoundBuffer m_walkInBuffer;
	sf::SoundBuffer m_shootBuffer;
	sf::SoundBuffer m_deadBuffer;
	sf::SoundBuffer m_leverBuffer;
	sf::SoundBuffer m_clickBuffer;
	sf::Sound m_sound;
	b2World* m_pWorld;
	std::vector<std::string> m_levelFiles;
	std::vector<std::string> m_musicFiles;
	std::vector<GameObject*> m_menuObjects;
	std::vector<MenuButton*> m_menuButtons;
	sf::Clock m_pauseClock;
	sf::Time m_pauseTime;
	Level* m_pLevel;
	MenuButton* m_over;
	bool m_bRunning;
	bool m_bMarkToChangeLevel;
	bool m_bChangeLevel;
	enum { MAINMENU, PREGAME, GAME, PAUSE, LOSE, ENDGAME } state;
	enum { MOUSE_OUT, MOUSE_OVER } mouse_state;
};

#endif // GAME_H