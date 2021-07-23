#include "State.h"

State::State() 
	: m_QuitRequested(false), m_Background(Sprite("assets/img/ocean.jpg")), 
		m_Music(Music("assets/audio/stageState.ogg"))
{
	m_Music.Play();
}

void State::LoadAssets()
{
	// Pre-load Assets
}

void State::Update(float dt)
{
	m_QuitRequested = SDL_QuitRequested();
}

void State::Render()
{
	m_Background.Render(0, 0);
}
