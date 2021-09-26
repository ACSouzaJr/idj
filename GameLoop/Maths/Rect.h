#pragma once
#include "Vec2.h"

struct Rect
{
	float x, y, w, h;

	Rect()
		: x(0), y(0), w(0), h(0) {}
	Rect(const float& x, const float& y, const float& w, const float& h)
		: x(x), y(y), w(w), h(h) {}

	bool Contains(Vec2 vec2);
};

