#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
class TextureManager
{
public:
	static TextureManager* Instance() {
		if(s_pInstance == nullptr) {
			s_pInstance = new TextureManager();
		}
		return s_pInstance;
	}
	bool load(std::string fileName, std::string id);
	void clearTextureMap() {
		m_textureMap.clear();
	}
	void clearFromTextureMap(std::string id) {
		m_textureMap.erase(id);
	}
	sf::Texture* getTexture(std::string id) {
		return m_textureMap[id];
	}
private:
	TextureManager() {}
	std::map<std::string, sf::Texture*> m_textureMap;
	static TextureManager* s_pInstance;
};

#endif // TEXTUREMANAGER_H