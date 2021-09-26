#include <SDL_image.h>
#include "Sprite.h"
#include "../../Resources.h"
#include "../../Game.h"

Sprite::Sprite(GameObject& associated)
	: m_Texture(nullptr), m_ClipRect({0, 0, 0, 0}), 
		m_Width(0), m_Height(0), Component(associated)
{
}

Sprite::Sprite(GameObject& associated, const char* file_path)
	: Sprite(associated)
{
	Open(file_path);
}

Sprite::~Sprite()
{
}

void Sprite::Open(const char* file_path)
{
	// Get image from resources
	m_Texture = Resources::GetImage(file_path);

	// Query texture size
	SDL_QueryTexture(m_Texture, nullptr, nullptr, &m_Width, &m_Height);

	SetClip(0, 0, m_Width, m_Height);
	m_Associated.m_Position = { 0, 0, (float)m_Width, (float)m_Height };
}

void Sprite::SetClip(int x, int y, int w, int h)
{
	m_ClipRect = { x, y, w, h };
}

void Sprite::Render()
{
	SDL_Rect dstrect = { (int)m_Associated.m_Position.x, (int)m_Associated.m_Position.y, m_ClipRect.w, m_ClipRect.h };
	SDL_RenderCopy(Game::GetInstance().GetRenderer(), m_Texture, &m_ClipRect, &dstrect);
}

void Sprite::Render(float x, float y)
{
	SDL_Rect dstrect = { (int)x, (int)y, m_ClipRect.w, m_ClipRect.h };
	SDL_RenderCopy(Game::GetInstance().GetRenderer(), m_Texture, &m_ClipRect, &dstrect);
}
