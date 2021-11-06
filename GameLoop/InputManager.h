#pragma once
#include <unordered_map>
#include <SDL.h>

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT
#define SPACE_KEY SDLK_SPACE

class InputManager
{
public:	

	static InputManager& GetInstance();
	void Update();

	bool KeyPress(int key) { return m_KeyState[key] && m_UpdateCounter == m_KeyUpdate[key]; };
	bool KeyRelease(int key) { return !m_KeyState[key] && m_UpdateCounter == m_KeyUpdate[key]; };
	bool IsKeyDown(int key) { return m_KeyState[key]; };

	bool MousePress(int button) { return m_MouseState[button] && m_MouseUpdate[button] == m_UpdateCounter; };
	bool MouseRelease(int button) { return !m_MouseState[button] && m_MouseUpdate[button] == m_UpdateCounter; };
	bool IsMouseDown(int button) { return m_MouseState[button]; };

	inline int GetMouseX() const { return m_MouseX; };
	inline int GetMouseY() const { return m_MouseY; };
	inline bool QuitRequested() const { return m_QuitRequested; };

private:
	InputManager() {};
	~InputManager() {};

private:
	bool m_MouseState[6] = { false };
	int m_MouseUpdate[6] = { 0 };

	std::unordered_map<int, bool> m_KeyState;
	std::unordered_map<int, int> m_KeyUpdate;

	bool m_QuitRequested = false;

	int m_UpdateCounter = 0;

	int m_MouseX;
	int m_MouseY;
};

