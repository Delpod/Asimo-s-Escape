#include "TextureManager.h"
#include <iostream>
TextureManager* TextureManager::s_pInstance = nullptr;

bool TextureManager::load(std::string fileName, std::string id) {
	sf::Texture* texture = new sf::Texture();
	if(!texture->loadFromFile(fileName)) {
		std::cerr << "Can't load file " << fileName << std::endl;
		return false;
	}
	
	m_textureMap[id] = texture;
	return true;
}