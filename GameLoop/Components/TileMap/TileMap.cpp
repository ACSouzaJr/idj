#include <fstream>
#include <string>
#include "TileMap.h"
#include "../../Camera.h"

TileMap::TileMap(GameObject& associated, const char* file_path, TileSet *tileSet)
	: Component(associated), m_TileSet(tileSet)
{
	Load(file_path);
}

TileMap::~TileMap()
{
	delete m_TileSet;
}

void TileMap::Load(const char* file_path)
{
	std::ifstream file(file_path);

	if (!file.is_open()) {
		std::cout << "Failed to open TileMap file!" << std::endl;
	}
	else {
		std::string line;
		std::getline(file, line, ',');
		m_Width = atoi(line.c_str());

		//std::cout << m_Width << std::endl;

		std::getline(file, line, ',');
		m_Height = atoi(line.c_str());

		//std::cout << m_Height << std::endl;

		std::getline(file, line, ',');
		m_Depth = atoi(line.c_str());

		//std::cout << m_Depth << std::endl;

		// empty line
		std::getline(file, line);
		std::getline(file, line);

		for (size_t z = 0; z < m_Depth; z++)
		{
			for (size_t y = 0; y < m_Height; y++)
			{
				for (size_t x = 0; x < m_Width; x++)
				{
					std::getline(file, line, ',');
					int index = atoi(line.c_str()) - 1;
					//std::cout << index + 1 << " ";
					m_TileMatrix.push_back(index);
				}
				std::getline(file, line); // line finish
				//std::cout << std::endl;
			}
			std::getline(file, line); // empty line
			//std::cout << std::endl;
		}
	}
}

void TileMap::SetTileSet(TileSet* tileSet)
{
	m_TileSet = tileSet;
}

int& TileMap::At(int x, int y, int z)
{
	// m_TileMatrix[x][y][z]
	return m_TileMatrix[x + m_Width * (y + m_Height * z)];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY)
{
	for (size_t y = 0; y < m_Height; y++)
	{
		for (size_t x = 0; x < m_Width; x++)
		{
			// Consider tile size and camera displacement to place tile
			int xPos = x * m_TileSet->GetTileWidth() + cameraX;
			int yPos = y * m_TileSet->GetTileHeight() + cameraY;
			int index = At(x, y, layer);

			// Tile is empty if index = -1
			if (index != -1)
			{
				m_TileSet->RenderTile(index, xPos, yPos);
			}
		}
	}
}

void TileMap::Render()
{
	for (size_t z = 0; z < m_Depth; z++)
	{
		RenderLayer(z, Camera::m_Pos.x, Camera::m_Pos.y);
	}
}
