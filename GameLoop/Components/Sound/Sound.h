#pragma once
#include <SDL_mixer.h>
#include "../Component.h"

class Sound : public Component
{
public:
	Sound(GameObject& associated);
	Sound(GameObject& associated, const char* file_path);
	~Sound();

	void Open(const char* file_path);
	void Play(int times = 1);
	void Stop();
	inline bool IsOpen() const { return m_Chunk != nullptr; }

	void Render() override {};
	void Update(float dt) override {};
	inline bool IsType(const char* type) const override { return type == "Sound"; };

private:
	Mix_Chunk* m_Chunk;
	int m_Channel;
};

