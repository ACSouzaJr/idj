#include <SDL.h>
#include "Music.h"
#include "Resources.h"

Music::Music() : m_Music(nullptr)
{
}

Music::Music(const char* file_path) : m_Music(nullptr)
{
	Open(file_path);
}

Music::~Music()
{
	// Stop Music
	Stop();
}

void Music::Open(const char* file_path)
{
	m_Music = Resources::GetMusic(file_path);
}

void Music::Play(int times)
{
	// Play music if exists
	if (IsOpen()) {
		// -1: play forever
		if (Mix_PlayMusic(m_Music, times) == -1) {
			SDL_Log("Mix_PlayMusic: %s\n", Mix_GetError());
			// well, there's no music, but most games don't break without music...
		}
	}
}

void Music::Stop(int msToStop)
{
	if (IsOpen()) {
		Mix_FadeOutMusic(msToStop);
	}
}
