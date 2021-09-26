#pragma once
#include <iostream>

struct Vec2
{
	float x, y;

	Vec2()
		: x(0), y(0) {}
	Vec2(const float& x, const float& y)
		: x(x), y(y) {}

	Vec2 add(const Vec2& other) const;
	Vec2 subtract(const Vec2& other) const;
	Vec2 multiply(const Vec2& other) const;
	Vec2 divide(const Vec2& other) const;

	Vec2 operator+(const Vec2& other) const;
	Vec2 operator-(const Vec2& other) const;
	Vec2 operator*(const Vec2& other) const;
	Vec2 operator/(const Vec2& other) const;

	bool operator==(const Vec2& other) const;
	bool operator!=(const Vec2& other) const;

	Vec2& operator+=(const Vec2& other);
	Vec2& operator-=(const Vec2& other);
	Vec2& operator*=(const Vec2& other);
	Vec2& operator/=(const Vec2& other);


	Vec2& GetRotated(float angle);
};

std::ostream& operator<<(std::ostream& stream, const Vec2& vector);