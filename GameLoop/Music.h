#pragma once
#include <SDL_mixer.h>

class Music
{
public:
	Music();
	Music(const char* file_path);
	~Music();

	void Open(const char* file_path);
	void Play(int times = -1);
	void Stop(int msToStop = 1500);
	bool IsOpen() const { return m_Music != nullptr; }
private:
	Mix_Music* m_Music;
};

