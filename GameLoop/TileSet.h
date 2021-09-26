#pragma once
#include "Components/Sprite/Sprite.h"

// Big sprite
// To render clip some part of the sprite
class TileSet
{
public:
	TileSet(int width, int height, const char* file_path);

	void RenderTile(unsigned index, float x, float y);
	inline int GetTileWidth() const { return m_TileWidth; };
	inline int GetTileHeight() const { return m_TileHeight; };

private:
	Sprite m_TileSet;
	int m_Rows, m_Columns;
	int m_TileWidth, m_TileHeight;
};

