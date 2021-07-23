#include "Sprite.h"
#include <SDL_image.h>
#include "Game.h"

Sprite::Sprite() 
	: m_Texture(nullptr), m_ClipRect({0, 0, 0, 0}), m_Width(0), m_Height(0)
{
}

Sprite::Sprite(const char* file_path) : m_Texture(nullptr)
{
	Open(file_path);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(m_Texture);
}

void Sprite::Open(const char* file_path)
{
	// Load image on file path
	// Before loading verify if an texture is already loaded
	if (IsOpen()) {
		SDL_DestroyTexture(m_Texture);
	}

	// Load Texture
	m_Texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file_path);
	if (m_Texture == nullptr) {
		SDL_Log("IMG_Load: %s\n", IMG_GetError());
		// handle error
		return;
	}

	// Query texture size
	SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_Width, &m_Height);

	SetClip(0, 0, m_Width, m_Height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
	m_ClipRect = { x, y, w, h };
}

void Sprite::Render(int x, int y)
{
	SDL_Rect dstrect = { x, y, m_ClipRect.w, m_ClipRect.h };
	SDL_RenderCopy(Game::GetInstance().GetRenderer(), m_Texture, &m_ClipRect, &dstrect);
}
