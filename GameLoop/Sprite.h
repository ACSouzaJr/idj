#pragma once
#include <SDL.h>

class Sprite
{
	// Load and use of textures(images) + rect
public:
	Sprite();
	Sprite(const char* file_path);
	~Sprite();

	void Open(const char* file_path);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y);
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	bool IsOpen() const { return m_Texture != nullptr; }
private:
	SDL_Texture* m_Texture;
	SDL_Rect m_ClipRect;
	int m_Width;
	int m_Height;
};

