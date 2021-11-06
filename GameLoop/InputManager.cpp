#include "InputManager.h"

InputManager& InputManager::GetInstance()
{
    static InputManager inputManager;

    return inputManager;
}

void InputManager::Update()
{
	SDL_Event event;
	m_QuitRequested = false;

	// Update triggered
	m_UpdateCounter++;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&m_MouseX, &m_MouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if (event.type == SDL_QUIT) {
			m_QuitRequested = true;
		}

		if (event.key.repeat) return;

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			m_MouseState[event.button.button] = true;
			m_MouseUpdate[event.button.button] = m_UpdateCounter;
		}
		
		if (event.type == SDL_MOUSEBUTTONUP) {
			m_MouseState[event.button.button] = false;
			m_MouseUpdate[event.button.button] = m_UpdateCounter;
		}

		if (event.type == SDL_KEYDOWN) {
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				m_QuitRequested = true;
			}
			// Se não, crie um objeto
			else {
				m_KeyState[event.key.keysym.sym] = true;
				m_KeyUpdate[event.key.keysym.sym] = m_UpdateCounter;
			}
		}
		
		if (event.type == SDL_KEYUP) {
			m_KeyState[event.key.keysym.sym] = false;
			m_KeyUpdate[event.key.keysym.sym] = m_UpdateCounter;
		}

		//printf("Type: %d, Key: %d, Count: %d\n", event.type, event.key.keysym.sym, m_KeyUpdate[event.key.keysym.sym]);
	}
}
