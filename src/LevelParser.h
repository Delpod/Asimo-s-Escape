#ifndef LEVELPARSER_H
#define LEVELPARSER_H
#include <vector>
#include "tinyxml2/tinyxml2.h"
#include "Level.h"
using namespace tinyxml2;

class LevelParser {
public:
	Level* parseLevel(const char* levelFile);
private:
	void parseTileLayer(XMLElement* pTileElement, Level *pLevel);
	void parseTextures(XMLElement *pTextureRoot);
	void parseObjectLayer(XMLElement* pObjectElement, Level *pLevel);
	
	int m_width;
	int m_height;
	int m_tilesetWidth;
};

#endif // LEVELPARSER_H