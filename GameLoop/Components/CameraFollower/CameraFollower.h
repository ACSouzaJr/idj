#pragma once
#include "../Component.h"

class CameraFollower : public Component
{
public:
	CameraFollower(GameObject& go);
	void Update(float dt) override;
	void Render() override {}
	bool IsType(const char* type) const override { return type == "CameraFollower"; };
};

