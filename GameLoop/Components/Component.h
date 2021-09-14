#pragma once
#include "../GameObject.h"	

// Add Game Logic
class Component
{
public:
	Component(GameObject& associated)
		: m_Associated(associated) {};

	virtual ~Component() {};

	virtual void Render() = 0;
	virtual void Update(float dt) = 0;
	virtual inline bool IsType(const char* type) const = 0;

protected:
	GameObject& m_Associated;
};

