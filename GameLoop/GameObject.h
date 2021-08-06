#pragma once
#include <vector>
#include <SDL.h>
#include "Components/Component.h"

// Interface for components logic
// Every GO has an position (m_Position)
// 
class GameObject
{
public:
	GameObject();
	~GameObject();


	void AddComponent(Component *component);
	void RemoveComponent(Component* component);
	Component* GetComponent(const char* type);
	void Update(float dt);
	void Render();
	void RequestDelete() { m_IsDead = true; };
	inline bool IsDead() const { return m_IsDead; };

public:
	SDL_Rect m_Position;

private:
	std::vector<Component*> m_Components;
	bool m_IsDead;
};

