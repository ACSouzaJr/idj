#pragma once
#include <SDL.h>
#include <memory>
#include <vector>
#include "Components/Sprite/Sprite.h"
#include "Music.h"
#include "GameObject.h"

class State
{
public:
	State();
	~State();

	void LoadAssets();
	void Update(float dt);
	void Render();
	void Input();
	void AddObject(int mouseX, int mouseY);
	bool QuitRequested() const { return m_QuitRequested; }

private:
	//Sprite m_Background;
	Music m_Music;
	bool m_QuitRequested;
	std::vector<std::unique_ptr<GameObject>> m_ObjectArray;
};

