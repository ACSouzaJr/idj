#include "Resources.h"
#include "Game.h"

std::unordered_map<const char*, SDL_Texture*> Resources::m_ImageTable;
std::unordered_map<const char*, Mix_Music*> Resources::m_MusicTable;
std::unordered_map<const char*, Mix_Chunk*> Resources::m_SoundTable;

SDL_Texture* Resources::GetImage(const char* file_path)
{
	// Load image on file path
	// Before loading verify if an texture is already loaded
	// If key not found in map iterator to end is returned
	if (m_ImageTable.find(file_path) != m_ImageTable.end()) {
		return m_ImageTable[file_path];
	}

	// Load Texture
	auto texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file_path);
	if (texture == nullptr) {
		SDL_Log("IMG_Load: %s\n", IMG_GetError());
		// handle error
		return nullptr;
	}

	// Cache texture and return
	m_ImageTable[file_path] = texture;
	return texture;
}

void Resources::ClearImages()
{
	for (auto itr = m_ImageTable.begin(); itr != m_ImageTable.end(); itr++)
	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part  and
		// itr->second stores the value part
		SDL_DestroyTexture(itr->second);
	}
	m_ImageTable.clear();
}

Mix_Music* Resources::GetMusic(const char* file_path)
{
	// Load music on file path
	// Before loading verify if an music is already loaded
	// If key not found in map iterator to end is returned
	if (m_MusicTable.find(file_path) != m_MusicTable.end()) {
		return m_MusicTable[file_path];
	}

	// Load Music
	auto music = Mix_LoadMUS(file_path);
	if (music == nullptr) {
		SDL_Log("Mix_LoadMUS(\"%s\"): %s\n", file_path, Mix_GetError());
		// this might be a critical error...
		return nullptr;
	}

	// Cache Music and return
	m_MusicTable[file_path] = music;
	return music;
}

void Resources::ClearMusics()
{
	for (auto itr = m_MusicTable.begin(); itr != m_MusicTable.end(); itr++)
	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part  and
		// itr->second stores the value part

		// Close and destroy the music
		Mix_FreeMusic(itr->second);
	}
	m_MusicTable.clear();
}

Mix_Chunk* Resources::GetSound(const char* file_path)
{
	// Load sound on file path
	// Before loading verify if an sound is already loaded
	// If key not found in map iterator to end is returned
	if (m_SoundTable.find(file_path) != m_SoundTable.end()) {
		return m_SoundTable[file_path];
	}

	// Load Music
	auto sound = Mix_LoadWAV(file_path);
	if (sound == nullptr) {
		// Load error
		SDL_Log("Mix_LoadWAV: %s\n", Mix_GetError());

		return nullptr;
	}

	// Cache Music and return
	m_SoundTable[file_path] = sound;
	return sound;
}

void Resources::ClearSounds()
{
	for (auto itr = m_SoundTable.begin(); itr != m_SoundTable.end(); itr++)
	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part  and
		// itr->second stores the value part

		// Close and destroy the music
		Mix_FreeChunk(itr->second);
	}
	m_SoundTable.clear();
}
