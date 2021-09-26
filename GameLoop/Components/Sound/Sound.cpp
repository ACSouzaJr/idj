#include <SDL.h>
#include "Sound.h"
#include "../../Resources.h"

Sound::Sound(GameObject& associated)
	: m_Chunk(nullptr), m_Channel(0), Component(associated)
{
}

Sound::Sound(GameObject& associated, const char* file_path)
	: Sound(associated)
{
	Open(file_path);
}

Sound::~Sound()
{
	if (IsOpen()) {
		// Wait for sound to play
		while (Mix_Playing(m_Channel) != 0) SDL_Delay(200); // Wait 200 ms
		Stop();		
	}
}

void Sound::Open(const char* file_path)
{
	m_Chunk = Resources::GetSound(file_path);
}

void Sound::Play(int times)
{
	if (IsOpen()) {
		// Play for (times + 1) number of times	
		// times default is 1
		m_Channel = Mix_PlayChannel(-1, m_Chunk, times - 1);

		if (m_Channel == -1) {
			SDL_Log("Mix_PlayChannel: %s\n", Mix_GetError());
			// may be critical error, or maybe just no channels were free.
			// you could allocated another channel in that case...
		}
	}
}

void Sound::Stop()
{
	if (IsOpen()) {
		Mix_HaltChannel(m_Channel);
	}
}
