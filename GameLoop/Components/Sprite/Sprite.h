#pragma once
#include <SDL.h>
#include "../Component.h"

class Sprite : public Component
{
	// Load and use of textures(images) + rect
public:
	Sprite(GameObject& associated);
	Sprite(GameObject& associated, const char* file_path);
	~Sprite();

	void Open(const char* file_path);
	void SetClip(int x, int y, int w, int h);
	void Render() override;
	void Update(float dt) override {};

	inline bool IsType(const char* type) const { return type == "Sprite"; };
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	inline bool IsOpen() const { return m_Texture != nullptr; }

private:
	SDL_Texture* m_Texture;
	SDL_Rect m_ClipRect;
	int m_Width;
	int m_Height;
};

