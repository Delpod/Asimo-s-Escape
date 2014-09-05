#ifndef TILE_H
#define TILE_H
#include "GameObject.h"

class Tile : public GameObject {
public:
	Tile(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int gid);
	int getGid() { return m_gid; }
	std::string type() { return std::string("Tile"); }
protected:
	int m_gid;
};

#endif // TILE_H