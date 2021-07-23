#include "Music.h"
#include <SDL.h>

Music::Music() : m_Music(nullptr)
{
}

Music::Music(const char* file_path) : m_Music(nullptr)
{
	Open(file_path);
}

Music::~Music()
{
	// Close and destroy the music
	Stop();
	Mix_FreeMusic(m_Music);
}

void Music::Open(const char* file_path)
{
	m_Music = Mix_LoadMUS(file_path);
	if (!IsOpen()) {
		SDL_Log("Mix_LoadMUS(\"%s\"): %s\n", file_path, Mix_GetError());
		// this might be a critical error...
	}
}

void Music::Play(int times)
{
	// Play music if exists
	// -1: play forever
	if (Mix_PlayMusic(m_Music, times) == -1) {
		SDL_Log("Mix_PlayMusic: %s\n", Mix_GetError());
		// well, there's no music, but most games don't break without music...
	}
}

void Music::Stop(int msToStop)
{
	Mix_FadeOutMusic(msToStop);
}
