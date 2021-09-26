#pragma once
#include <unordered_map>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

class Resources
{
public:

	static SDL_Texture* GetImage(const char* file_path);
	static void ClearImages();

	static Mix_Music* GetMusic(const char* file_path);
	static void ClearMusics();

	static Mix_Chunk* GetSound(const char* file_path);
	static void ClearSounds();

private:
	static std::unordered_map<const char*, SDL_Texture*> m_ImageTable;
	static std::unordered_map<const char*, Mix_Music*> m_MusicTable;
	static std::unordered_map<const char*, Mix_Chunk*> m_SoundTable;
};

