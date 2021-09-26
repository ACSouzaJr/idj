#include "Vec2.h"

Vec2 Vec2::add(const Vec2& other) const
{
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::subtract(const Vec2& other) const
{
	return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::multiply(const Vec2& other) const
{
	return Vec2(x * other.x, y * other.y);
}

Vec2 Vec2::divide(const Vec2& other) const
{
	return Vec2(x / other.x, y / other.y);
}


Vec2 Vec2::operator+(const Vec2& other) const
{
	return add(other);
}

Vec2 Vec2::operator-(const Vec2& other) const
{
	return subtract(other);
}

Vec2 Vec2::operator*(const Vec2& other) const
{
	return multiply(other);
}

Vec2 Vec2::operator/(const Vec2& other) const
{
	return divide(other);
}

bool Vec2::operator==(const Vec2& other) const
{
	return x == other.x && y == other.y;
}

bool Vec2::operator!=(const Vec2& other) const
{
	return !(*this == other); // Reverse of the equal operator
}

Vec2& Vec2::operator+=(const Vec2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vec2& Vec2::operator*=(const Vec2& other)
{
	x *= other.x;
	y *= other.y;

	return *this;
}

Vec2& Vec2::operator/=(const Vec2& other)
{
	x /= other.x;
	y /= other.y;

	return *this;
}

Vec2& Vec2::GetRotated(float angle)
{
	// x’ = x * cosθ - y * sinθ
	// y’ = y * cosθ + x * sinθ

	float newX = x * cos(angle) - y * sin(angle);
	float newY = y * cos(angle) + x * sin(angle);

	x = newX;
	y = newY;

	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
{
	stream << "Vec2: (" << vector.x << ", " << vector.y << ")";
	return stream;
}