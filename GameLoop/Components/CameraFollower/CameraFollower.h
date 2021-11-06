#pragma once
#include "../Component.h"

class CameraFollower : Component
{
public:
	CameraFollower(GameObject& go);
	void Update(float dt);
	void Render() {}
	bool Is(const char* type) const { return type == "CameraFollower"; };
};

