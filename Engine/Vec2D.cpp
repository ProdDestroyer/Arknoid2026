#include "Vec2D.h"
#include <cmath>

Vec2D::Vec2D(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

Vec2D Vec2D::operator+(const Vec2D& vec) const
{
	return Vec2D(this->x + vec.x, this->y + vec.y);
}

Vec2D& Vec2D::operator+=(const Vec2D& vec)
{
	return *this = *this + vec;
}

Vec2D Vec2D::operator*(const float scale) const
{
	return Vec2D(this->x * scale, this->y * scale);
}

Vec2D& Vec2D::operator*=(const float scale)
{
	return *this = *this * scale;
}

Vec2D Vec2D::operator-(const Vec2D& vec) const
{
	return Vec2D(this->x - vec.x, this->y - vec.y);
}

Vec2D& Vec2D::operator-=(const Vec2D& vec)
{
	Vec2D auxV = vec * 2.0f;
	return *this = *this - vec;
}

bool Vec2D::operator==(const Vec2D& vec) const
{
	return x == vec.x && y == vec.y;
}

bool Vec2D::operator!=(const Vec2D& vec) const
{
	return !(*this == vec);
}

float Vec2D::length() const
{
	return std::sqrt(lengthSqrd());
}

float Vec2D::lengthSqrd() const
{
	return this->x * this->x + this->y * this->y;
}

void Vec2D::normalize()
{
	*this = normalized();
}

Vec2D Vec2D::normalized() const
{
	return (this->x != 0 || this->y != 0) ? *this * (1 / length()) : *this;
}
