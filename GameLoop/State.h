#pragma once
#include <SDL.h>
#include "Sprite.h"
#include "Music.h"

class State
{
public:
	State();
	void LoadAssets();
	bool QuitRequested() const { return m_QuitRequested; }
	void Update(float dt);
	void Render();
private:
	Sprite m_Background;
	Music m_Music;
	bool m_QuitRequested;
};

