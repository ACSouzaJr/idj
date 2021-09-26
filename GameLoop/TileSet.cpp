#include "TileSet.h"
#include "GameObject.h"

TileSet::TileSet(int tileWidth, int tileHeight, const char* file_path)
	: m_TileWidth(tileWidth), m_TileHeight(tileHeight), m_TileSet(*(new GameObject()), file_path)
{
	m_Columns = m_TileSet.GetWidth() / m_TileWidth;
	m_Rows = m_TileSet.GetHeight() / m_TileHeight;
}

void TileSet::RenderTile(unsigned index, float x, float y)
{

	int tileCount = m_Columns * m_Rows;
	if (index >= 0 && index <= tileCount - 1)
	{
		// Set clipping position
		int newX = (index % m_Columns) * m_TileWidth;
		int newY = floor(index / m_Columns) * m_TileHeight;

		m_TileSet.SetClip(newX, newY, m_TileWidth, m_TileHeight);

		// Render Sprite
		m_TileSet.Render(x, y);
	}
}
