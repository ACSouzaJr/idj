#pragma once
#include <vector>
#include "../Component.h"
#include "../../TileSet.h"

class TileMap : public Component
{
public:
	TileMap(GameObject& associated, const char* file_path, TileSet* tileSet);
	~TileMap();
	void Load(const char* file_path);
	void SetTileSet(TileSet *tileSet);
	int& At(int x, int y, int z = 0);
	void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
	void Render() override;
	void Update(float dt) override {};
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline int GetDepth() const { return m_Depth; }
	inline bool IsType(const char* type) const override { return type == "TileMap"; };

private:
	std::vector<int> m_TileMatrix;
	TileSet *m_TileSet;
	int m_Width;
	int m_Height;
	int m_Depth;
};

