#include "Game.h"
#include "LevelParser.h"
#include "InteractionObject.h"

Game* Game::s_pInstance = nullptr;

Game::Game() : m_gameWidth(0), m_gameHeight(0), m_currentLevel(1), m_bLevelComplete(false), m_pWindow(nullptr), m_bRunning(false), m_bMarkToChangeLevel(false) {
	m_levelFiles.push_back(std::string("data/maps/map0.tmx"));
	m_levelFiles.push_back(std::string("data/maps/map1.tmx"));
	m_levelFiles.push_back(std::string("data/maps/map2.tmx"));
	m_levelFiles.push_back(std::string("data/maps/map3.tmx"));
	m_levelFiles.push_back(std::string("data/maps/map4.tmx"));
	m_levelFiles.push_back(std::string("data/maps/map5.tmx"));
	m_levelFiles.push_back(std::string("data/maps/map6.tmx"));
	m_levelFiles.push_back(std::string("data/maps/map0.tmx"));
	m_musicFiles.push_back(std::string("data/music/stuff.ogg"));
	m_musicFiles.push_back(std::string("data/music/stuff2.ogg"));
	m_musicFiles.push_back(std::string("data/music/stuff3.ogg"));
	m_musicFiles.push_back(std::string("data/music/stuff4.ogg"));
	m_musicFiles.push_back(std::string("data/music/stuff5.ogg"));
	m_musicFiles.push_back(std::string("data/music/stuff6.ogg"));
	m_musicFiles.push_back(std::string("data/music/stuff7.ogg"));
	m_musicFiles.push_back(std::string("data/music/stuff8.ogg"));
	m_musicFiles.push_back(std::string("data/music/stuff9.ogg"));
	m_crushBuffer.loadFromFile("data/sfx/crush.wav");
	m_walkInBuffer.loadFromFile("data/sfx/walkin.wav");
	m_shootBuffer.loadFromFile("data/sfx/shoot.wav");
	m_deadBuffer.loadFromFile("data/sfx/dead.wav");
	m_leverBuffer.loadFromFile("data/sfx/lever.wav");
	m_clickBuffer.loadFromFile("data/sfx/click.wav");
	m_pauseTime = sf::seconds(0.0f);
	m_pWorld = nullptr;
}

void Game::init(sf::VideoMode vm, const char* name, int styles) {
	m_pWindow = new sf::RenderWindow(vm, name, styles);
	m_pWindow->setVerticalSyncEnabled(true);
	sf::Image icon;
	icon.loadFromFile("data/gfx/icon.png");
	m_pWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	initMainMenuState();
	m_bRunning = true;
}

void Game::handleEvents() {
	sf::Event event;
	while(m_pWindow->pollEvent(event)) {
		if(state != GAME) {
			bool isOver = false;
			if(event.type == sf::Event::MouseMoved) {
				for(unsigned int i = 0; i < m_menuButtons.size(); ++i) {
					sf::Vector2i pos = sf::Mouse::getPosition(*m_pWindow);
					sf::FloatRect spritePos = m_menuButtons[i]->getSprite()->getGlobalBounds();
					if(pos.x > spritePos.left && pos.x < (spritePos.left + spritePos.width) &&
						pos.y > spritePos.top && pos.y < (spritePos.top + spritePos.height)) {
							isOver = true;
							m_menuButtons[i]->changeState(1);
							m_over = m_menuButtons[i];
					} else {
							m_menuButtons[i]->changeState(0);
					}
				}
				mouse_state = isOver ? MOUSE_OVER : MOUSE_OUT;
			} else if(mouse_state == MOUSE_OVER && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				playClick();
				switch(m_over->getCallbackId())
				{
				case 1:
					mouse_state = MOUSE_OUT;
					initMainMenuState();
					break;
				case 2:
					mouse_state = MOUSE_OUT;
					initGameState();
					break;
				case 3:
					mouse_state = MOUSE_OUT;
					initNextGameState();
					break;
				case 4:
					mouse_state = MOUSE_OUT;
					returnToGame();
					break;
				case 5:
					mouse_state = MOUSE_OUT;
					m_bChangeLevel = false;
					initPreGame();
					break;
				case 6:
					quit();
					break;
				default:
					break;
				}
			} else if(state == MAINMENU && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				quit();
		} else {
			if(event.type == sf::Event::KeyReleased) {
				if(event.key.code == sf::Keyboard::Escape) {
					initPauseMenuState();
				} else if((event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::W) && m_pLevel->getInteractionObject() != nullptr) {
					if(dynamic_cast<InteractionObject*>(m_pLevel->getInteractionObject()))
						dynamic_cast<InteractionObject*>(m_pLevel->getInteractionObject())->interact();
				}
			} else if(event.type == sf::Event::LostFocus) {
				initPauseMenuState();
			}
		}
		
		if(event.type == sf::Event::Closed) {
			quit();
		}
	}
}

void Game::draw() {
	m_pWindow->clear(sf::Color(0,0,0));
	if(state != GAME) {
		for(unsigned int i = 0; i < m_menuObjects.size(); ++i) 
			m_pWindow->draw(*(*m_menuObjects[i]).getSprite());
		for(unsigned int i = 0; i < m_menuButtons.size(); ++i)
			m_pWindow->draw(*(*m_menuButtons[i]).getSprite());
	} else {
		m_pLevel->draw(m_pWindow);
	}
	m_pWindow->display();
}

void Game::update() {
	if(state != GAME) {
		for(unsigned int i = 0; i < m_menuObjects.size(); ++i)
			m_menuObjects[i]->update(m_pauseTime);
		for(unsigned int i = 0; i < m_menuButtons.size(); ++i)
			m_menuButtons[i]->update(m_pauseTime);
	} else {
		m_pLevel->update(m_pauseTime);
		m_pWorld->Step(1.0f/60.0f, 6, 2);
	}
	m_pauseTime = m_pauseTime.Zero;
	if(m_bMarkToChangeLevel) {
		initNextGameState();
		m_bMarkToChangeLevel = false;
	}
}

void Game::clean() {
	m_pWindow->close();
	m_menuObjects.clear();
	m_menuButtons.clear();
	if(m_pWorld != nullptr)
		delete m_pWorld;
	if(m_pWindow != nullptr)
		delete m_pWindow;
}

void Game::initMainMenuState() {
	if(m_pWorld != nullptr) {
		delete m_pWorld;
		m_pWorld = nullptr;
	}
	if(m_music.openFromFile(m_musicFiles[0])) {
		m_music.setLoop(true);
		m_music.play();
	}
	m_currentLevel = 1;
	TextureManager::Instance()->clearTextureMap();
	clearMenuObjects();
	TextureManager::Instance()->load("data/gfx/logo.png", "logo");
	TextureManager::Instance()->load("data/gfx/startbutton.png", "startbutton");
	TextureManager::Instance()->load("data/gfx/exitbutton.png", "exitbutton");
	sf::Texture* pTempTexture = TextureManager::Instance()->getTexture("logo");
	GameObject* gameObject = new GameObject(*pTempTexture, sf::Vector2f(
								(m_pWindow->getView().getSize().x - pTempTexture->getSize().x) / 2.0f, 100.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x , pTempTexture->getSize().y));
	m_menuObjects.push_back(gameObject);
	pTempTexture = TextureManager::Instance()->getTexture("startbutton");
	MenuButton* menuButton = new MenuButton(*pTempTexture, sf::Vector2f((
								m_pWindow->getView().getSize().x - pTempTexture->getSize().x/2.0f) / 2.0f, 200.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x / 2, pTempTexture->getSize().y), 5);
	m_menuButtons.push_back(menuButton);
	pTempTexture = TextureManager::Instance()->getTexture("exitbutton");
	menuButton = new MenuButton(*pTempTexture, sf::Vector2f((
								m_pWindow->getView().getSize().x - pTempTexture->getSize().x/2.0f) / 2.0f, 300.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x / 2, pTempTexture->getSize().y), 6);
	m_menuButtons.push_back(menuButton);
	state = MAINMENU;
}

void Game::initLoseMenuState() {
	if(m_pWorld != nullptr) {
		delete m_pWorld;
		m_pWorld = nullptr;
	}
	TextureManager::Instance()->clearTextureMap();
	clearMenuObjects();
	playDead();
	TextureManager::Instance()->load("data/gfx/lose.png", "lose");
	TextureManager::Instance()->load("data/gfx/retrybutton.png", "retrybutton");
	TextureManager::Instance()->load("data/gfx/mainmenubutton.png", "mainmenubutton");
	sf::Texture* pTempTexture = TextureManager::Instance()->getTexture("lose");
	GameObject* gameObject = new GameObject(*pTempTexture, sf::Vector2f(
								(m_pWindow->getView().getSize().x - pTempTexture->getSize().x) / 2.0f, 100.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x , pTempTexture->getSize().y));
	m_menuObjects.push_back(gameObject);
	pTempTexture = TextureManager::Instance()->getTexture("retrybutton");
	MenuButton* menuButton = new MenuButton(*pTempTexture, sf::Vector2f((
								m_pWindow->getView().getSize().x - pTempTexture->getSize().x/2.0f) / 2.0f, 200.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x / 2.0f, pTempTexture->getSize().y), 2);
	m_menuButtons.push_back(menuButton);
	pTempTexture = TextureManager::Instance()->getTexture("mainmenubutton");
	menuButton = new MenuButton(*pTempTexture, sf::Vector2f((
								m_pWindow->getView().getSize().x - pTempTexture->getSize().x/2.0f) / 2.0f, 300.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x / 2.0f, pTempTexture->getSize().y), 1);
	m_menuButtons.push_back(menuButton);
	state = LOSE;
}

void Game::initPauseMenuState() {
	m_pauseClock.restart();
	TextureManager::Instance()->load("data/gfx/pause.png", "pause");
	TextureManager::Instance()->load("data/gfx/returnbutton.png", "returnbutton");
	TextureManager::Instance()->load("data/gfx/mainmenubutton.png", "mainmenubutton");
	sf::Texture* pTempTexture = TextureManager::Instance()->getTexture("pause");
	GameObject* gameObject = new GameObject(*pTempTexture, sf::Vector2f(
								(m_pWindow->getView().getSize().x - pTempTexture->getSize().x) / 2.0f, 100.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x , pTempTexture->getSize().y));
	m_menuObjects.push_back(gameObject);
	pTempTexture = TextureManager::Instance()->getTexture("returnbutton");
	MenuButton* menuButton = new MenuButton(*pTempTexture, sf::Vector2f((
								m_pWindow->getView().getSize().x - pTempTexture->getSize().x/2.0f) / 2.0f, 200.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x / 2.0f, pTempTexture->getSize().y), 4);
	m_menuButtons.push_back(menuButton);
	pTempTexture = TextureManager::Instance()->getTexture("mainmenubutton");
	menuButton = new MenuButton(*pTempTexture, sf::Vector2f((
								m_pWindow->getView().getSize().x - pTempTexture->getSize().x/2.0f) / 2.0f, 300.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x / 2.0f, pTempTexture->getSize().y), 1);
	m_menuButtons.push_back(menuButton);
	state = PAUSE;
}

void Game::initGameState() {
	TextureManager::Instance()->clearTextureMap();
	clearMenuObjects();
	if(m_bChangeLevel) {
		m_music.stop();
		if(m_music.openFromFile(m_musicFiles[(m_currentLevel - 1) % (m_musicFiles.size() - 1) + 1])) {
			m_music.setLoop(true);
			m_music.play();
		}
		m_bChangeLevel = false;
	}
	b2Vec2 gravity(0.0f, 50.0f);
	m_pWorld = new b2World(gravity);
	LevelParser parser;
	m_pLevel = parser.parseLevel(m_levelFiles[m_currentLevel - 1].c_str());
	state = GAME;
}

void Game::initNextGameState() {
	++m_currentLevel;
	
	delete m_pWorld;
	m_pWorld = nullptr;
	if(m_currentLevel > m_levelFiles.size()) {
		initGameEnd();
	} else {
		m_bChangeLevel = true;
		initGameState();
	}
}

void Game::initPreGame() {
	TextureManager::Instance()->clearTextureMap();
	clearMenuObjects();
	if(m_music.openFromFile(m_musicFiles[m_currentLevel])) {
		m_music.setLoop(true);
		m_music.play();
	}
	TextureManager::Instance()->load("data/gfx/introtext.png", "introtext");
	TextureManager::Instance()->load("data/gfx/continuebutton.png", "continuebutton");
	sf::Texture* pTempTexture = TextureManager::Instance()->getTexture("introtext");
	GameObject* gameObject = new GameObject(*pTempTexture, sf::Vector2f(0.0f, 0.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x , pTempTexture->getSize().y));
	m_menuObjects.push_back(gameObject);
	pTempTexture = TextureManager::Instance()->getTexture("continuebutton");
	MenuButton* menuButton = new MenuButton(*pTempTexture, sf::Vector2f((
								m_pWindow->getView().getSize().x - pTempTexture->getSize().x/2.0f) / 2.0f, 310.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x / 2.0f, pTempTexture->getSize().y), 2);
	m_menuButtons.push_back(menuButton);
	state = PREGAME;
}

void Game::initGameEnd() {
	TextureManager::Instance()->clearTextureMap();
	clearMenuObjects();
	TextureManager::Instance()->load("data/gfx/outrotext.png", "outrotext");
	TextureManager::Instance()->load("data/gfx/continuebutton.png", "continuebutton");
	sf::Texture* pTempTexture = TextureManager::Instance()->getTexture("outrotext");
	GameObject* gameObject = new GameObject(*pTempTexture, sf::Vector2f(0.0f, 0.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x , pTempTexture->getSize().y));
	m_menuObjects.push_back(gameObject);
	pTempTexture = TextureManager::Instance()->getTexture("continuebutton");
	MenuButton* menuButton = new MenuButton(*pTempTexture, sf::Vector2f((
								m_pWindow->getView().getSize().x - pTempTexture->getSize().x/2.0f) / 2.0f, 273.0f - pTempTexture->getSize().y/2.0f),
								sf::IntRect(0, 0, pTempTexture->getSize().x / 2.0f, pTempTexture->getSize().y), 1);
	m_menuButtons.push_back(menuButton);
	state = ENDGAME;
}

void Game::returnToGame() {
	state = GAME;
	m_pauseTime = sf::seconds(m_pauseClock.getElapsedTime().asSeconds());
}