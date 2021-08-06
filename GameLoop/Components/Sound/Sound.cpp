#include "Sound.h"

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
		Stop();
		Mix_FreeChunk(m_Chunk);
	}
}

void Sound::Open(const char* file_path)
{
	m_Chunk = Mix_LoadWAV("sample.wav");
	if (!m_Chunk) {
		// Load error
		printf("Mix_LoadWAV: %s\n", Mix_GetError());
	}
}

void Sound::Play(int times)
{
	// Play for (times + 1) number of times
	// times default is 1
	m_Channel = Mix_PlayChannel(-1, m_Chunk, times - 1);
}

void Sound::Stop()
{
	if (IsOpen()) {
		Mix_HaltChannel(m_Channel);
	}
}
