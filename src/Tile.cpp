#include "Tile.h"

Tile::Tile(sf::Texture &texture, sf::Vector2f position, sf::IntRect textureRect, int gid) :
GameObject(texture, position, textureRect), m_gid(gid) {
	deadly = ((m_gid % 6) > 3 || (m_gid % 6) == 0) ? true : false;
}