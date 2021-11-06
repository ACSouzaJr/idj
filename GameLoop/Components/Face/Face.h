#pragma once
#include "../Component.h"

class Face : public Component
{
public:
	Face(GameObject& associated);

	void Damage(int damage);

	void Render() override {};
	void Update(float dt) override;
	inline bool IsType(const char* type) const override { return type == "Face"; };

private:
	int m_Hitpoints;
};

