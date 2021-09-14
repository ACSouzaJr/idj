#pragma once
#include <SDL.h>
#include "State.h"

class Game
{
private:
	Game(const char* title, int width, int height);
public:
	~Game();
	static Game& GetInstance();
	SDL_Renderer* GetRenderer() const { return m_Renderer; }
	State& GetState() const { return *m_State; }
	void Run();
private:
	static Game* s_Instance;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	State* m_State;
};

