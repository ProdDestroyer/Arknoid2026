#include "Rectangle2D.h"

Rectangle2D::Rectangle2D(const Vec2D& topLeftCorner, const Vec2D& dimensions, const Color& color) :
	topLeftCorner(topLeftCorner),
	dimensions(dimensions),
	color(color)
{

}

const Vec2D& Rectangle2D::GetTopLeftCorner() const
{
	return topLeftCorner;
}

const float Rectangle2D::GetWidth() const
{
	return dimensions.x;
}

const float Rectangle2D::GetHeight() const
{
	return dimensions.y;
}

const Vec2D& Rectangle2D::GetCenter() const
{
	return Vec2D{ topLeftCorner.x + dimensions.x / 2.0f, topLeftCorner.y + dimensions.y / 2.0f};
}

const Color& Rectangle2D::GetColor() const
{
	return color;
}

void Rectangle2D::Shift(const Vec2D& shift)
{
	topLeftCorner += shift;
}

void Rectangle2D::SetTopLeftCorner(const Vec2D& newTopLeftCorner)
{
	topLeftCorner = newTopLeftCorner;
}
