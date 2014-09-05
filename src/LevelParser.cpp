#include "LevelParser.h"
#include <Box2D/Box2D.h>
#include <iostream>
#include "base64/base64.h"
#include "zlib/zlib.h"
#include "Game.h"
#include "Layer.h"
#include "TextureManager.h"
#include "AnimatedObject.h"
#include "Enemy.h"
#include "Tile.h"
#include "ExitGate.h"
#include "Lever.h"
#include "Box.h"
#include "Barrier.h"

Level* LevelParser::parseLevel(const char* levelFile) {
	XMLDocument levelDocument(true, COLLAPSE_WHITESPACE);
	levelDocument.LoadFile(levelFile);
		
	TextureManager::Instance()->load("data/gfx/wkey.png", "wKey");
	
	Level* pLevel = new Level();
	
	XMLElement* pRoot = levelDocument.RootElement();
	
	pRoot->QueryIntAttribute("width", &m_width);
	pRoot->QueryIntAttribute("height", &m_height);
	
	
	for(XMLElement* e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("tileset")) {
			TextureManager::Instance()->load(e->FirstChildElement()->Attribute("source"),
									 e->Attribute("name"));
			e->FirstChildElement()->QueryIntAttribute("width", &m_tilesetWidth);
			pLevel->m_tileset = TextureManager::Instance()->getTexture(e->Attribute("name"));
		}
	}
	
	XMLElement* pProperties = pRoot->FirstChildElement();
	
	for(XMLElement* e = pProperties->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("property"))
			parseTextures(e);
	}

	for(XMLElement* e = pRoot->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("objectgroup") || e->Value() == std::string("layer")) {
			if(e->FirstChildElement()->Value() == std::string("object") ||
				(e->FirstChildElement()->NextSiblingElement() != 0 && e->FirstChildElement()->NextSiblingElement()->Value() == std::string("object"))) {
				parseObjectLayer(e, pLevel);
			} else if(e->FirstChildElement()->Value() == std::string("data") ||
                    (e->FirstChildElement()->NextSiblingElement() != 0 && e->FirstChildElement()->NextSiblingElement()->Value() == std::string("data"))) {
				parseTileLayer(e, pLevel);
			}
		}
	}
	
	pLevel->setMapWidth(m_width);
	return pLevel;
}

void LevelParser::parseTileLayer(XMLElement* pTileElement, Level* pLevel) {
	Layer* pLayer = new Layer();
	
	bool collidable = false;
	std::vector<std::vector<int>> data;
	
	std::string decodedIDs;
	XMLElement* pDataNode;
	
	for(XMLElement* e = pTileElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("properties")) {
			for(XMLElement* property = e->FirstChildElement(); property != nullptr; property = property->NextSiblingElement()) {
				if(property->Value() == std::string("property")) {
					if(property->Attribute("name") == std::string("collidable")) {
						collidable = true;
					}
				}
			}
		}
		
		if(e->Value() == std::string("data")) {
			pDataNode = e;
		}
	}
	
	for(XMLNode* e = pDataNode->FirstChild(); e != nullptr; e = e->NextSibling()){
		XMLText* text = e->ToText();
		decodedIDs = base64_decode(text->Value());
	}
	
	uLongf numGids = m_width * m_height * sizeof(int);
	std::vector<unsigned> gids(numGids);
	uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());
	
	std::vector<int> layerRow(m_width);
	
	for(int i = 0; i < m_height; ++i) {
		data.push_back(layerRow);
	}
	
	
	for(int rows = 0; rows < m_height; ++rows) {
		for(int cols = 0; cols < m_width; ++cols) {
			data[rows][cols] = gids[rows * m_width + cols];
			if(data[rows][cols] > 0) {
				GameObject* pTempGameObject = new Tile(*(pLevel->getTileset()), sf::Vector2f(cols * 32, rows * 32),
					sf::IntRect((data[rows][cols]-1) % (m_tilesetWidth/33) * 33,
					(int)((data[rows][cols]-1) / (m_tilesetWidth / 33)) * 33, 32, 32), data[rows][cols]);
				if(collidable)
					pTempGameObject->createCollidable();
				pLayer->getGameObjects()->push_back(pTempGameObject);
			}
		}
	}
	
	if(collidable) {
		pLevel->getCollisionLayers()->push_back(pLayer);
	}
	
	pLevel->getTileLayers()->push_back(pLayer);
}
void LevelParser::parseTextures(XMLElement* pTextureRoot) {
	TextureManager::Instance()->load(pTextureRoot->Attribute("value"),
									 pTextureRoot->Attribute("name"));
}

void LevelParser::parseObjectLayer(XMLElement* pObjectElement, Level* pLevel) {
	Layer* pLayer = new Layer();
	
	bool collidable = false;
	bool interactive = false;
	
	for(XMLElement* e = pObjectElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("properties")) {
			for(XMLElement* property = e->FirstChildElement(); property != nullptr; property = property->NextSiblingElement()) {
				if(property->Value() == std::string("property")) {
					if(property->Attribute("name") == std::string("collidable")) {
						collidable = true;
					} else if(property->Attribute("name") == std::string("interactive")) {
						interactive = true;
					}
				}
			}
		}
	}
	
	for(XMLElement* e = pObjectElement->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("object")) {
			int x, y, width, height, numFrames = 1;
			double animSpeed = 100.0, speed = 1.0, waitingTime = 100.0, begin = 0, end = 0;
			std::string textureID, textureID2, barrierID;
			std::string type;
			bool standing = false, lookingSide = false;
			e->QueryIntAttribute("x", &x);
			e->QueryIntAttribute("y", &y);
			GameObject* gameObject;
			
			for(XMLElement* properties = e->FirstChildElement(); properties != nullptr;
															properties = properties->NextSiblingElement()) {
				if(properties->Value() == std::string("properties")) {
					for(XMLElement* property = properties->FirstChildElement(); property != nullptr;
															property = property->NextSiblingElement()) {
						if(property->Value() == std::string("property")) {
							if(property->Attribute("name") == std::string("numFrames")) {
								property->QueryIntAttribute("value", &numFrames);
							} else if(property->Attribute("name") == std::string("height")) {
								property->QueryIntAttribute("value", &height);
							} else if(property->Attribute("name") == std::string("textureID")) {
								textureID = property->Attribute("value");
							} else if(property->Attribute("name") == std::string("textureID2")) {
								textureID2 = property->Attribute("value");
							} else if(property->Attribute("name") == std::string("barrierID")) {
								barrierID = property->Attribute("value");
							} else if(property->Attribute("name") == std::string("width")) {
								property->QueryIntAttribute("value", &width);
							} else if(property->Attribute("name") == std::string("animSpeed")) {
								property->QueryDoubleAttribute("value", &animSpeed);
							} else if(property->Attribute("name") == std::string("speed")) {
								property->QueryDoubleAttribute("value", &speed);
							} else if(property->Attribute("name") == std::string("waitingTime")) {
								property->QueryDoubleAttribute("value", &waitingTime);
							} else if(property->Attribute("name") == std::string("begin")) {
								property->QueryDoubleAttribute("value", &begin);
							} else if(property->Attribute("name") == std::string("end")) {
								property->QueryDoubleAttribute("value", &end);
							} else if(property->Attribute("name") == std::string("standing")) {
								standing = property->BoolAttribute("value");
							} else if(property->Attribute("name") == std::string("lookingSide")) {
								lookingSide = property->BoolAttribute("value");
							}
						}
					}
				}
			}
			if(e->Attribute("type") == std::string("GameObject")) {
				gameObject = new GameObject(*TextureManager::Instance()->getTexture(textureID),
				sf::Vector2f(x-width, y-height), sf::IntRect(0, 0, width, height));
			} else if(e->Attribute("type") == std::string("AnimatedObject")) {
				gameObject = new AnimatedObject(*TextureManager::Instance()->getTexture(textureID),
				sf::Vector2f(x, y), sf::IntRect(0, 0, width, height), numFrames, animSpeed);
			} else if(e->Attribute("type") == std::string("Enemy")) {
				gameObject = new Enemy(*TextureManager::Instance()->getTexture(textureID),
				*TextureManager::Instance()->getTexture(textureID2), sf::Vector2f(x-29, y-55),
				speed, waitingTime, begin*32, end*32, standing, lookingSide);
			} else if(e->Attribute("type") == std::string("Player")) {
				gameObject = new Player(*TextureManager::Instance()->getTexture(textureID),
				sf::Vector2f(x-15, y-43), sf::IntRect(0, 0, 15, 43), 4, 0.12f);
				pLevel->setPlayer(dynamic_cast<Player*>(gameObject));
			} else if(e->Attribute("type") == std::string("ExitGate")) {
				gameObject = new ExitGate(*TextureManager::Instance()->getTexture(textureID),
				sf::Vector2f(x-width, y-height), sf::IntRect(0, 0, width, height));
			} else if(e->Attribute("type") == std::string("Lever")) {
				gameObject = new Lever(*TextureManager::Instance()->getTexture(textureID),
				sf::Vector2f(x-width, y-height), sf::IntRect(0, 0, width, height), barrierID);
			} else if(e->Attribute("type") == std::string("Box")) {
				gameObject = new Box(*TextureManager::Instance()->getTexture(textureID),
				sf::Vector2f(x-width, y-height), sf::IntRect(0, 0, width, height));
			} else if(e->Attribute("type") == std::string("Barrier")) {
				gameObject = new Barrier(*TextureManager::Instance()->getTexture(textureID),
				sf::Vector2f(x-width, y-height), sf::IntRect(0, 0, width, height));
				pLevel->getBarrierMap()->insert(std::pair<std::string, Barrier*>(barrierID, dynamic_cast<Barrier*>(gameObject)));
			}
			
			
			if(collidable)
					gameObject->createCollidable();
			
			pLayer->getGameObjects()->push_back(gameObject);
		}
	}
	
	if(collidable) {
		pLevel->getCollisionLayers()->push_back(pLayer);
	}
	
	if(interactive) {
		pLevel->getInteractionLayers()->push_back(pLayer);
	}
	
	pLevel->getObjectLayers()->push_back(pLayer);
}