#pragma once
#include "Maths/Vec2.h"
#include "GameObject.h"

class Camera
{
public:
	static void Follow(GameObject* newFocus);
	static void Unfollow();
	static void Update(float dt);

public:
	static Vec2 m_Pos;
	static Vec2 m_Speed;

private:
	static GameObject* m_Focus;
};

