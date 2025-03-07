#include "Brick.h"

Brick::Brick(const Vec2D& topLeftCorner, const Vec2D& dimensions, const Color& color) :
	rectangle(topLeftCorner, dimensions)
{
	this->color = color;
}

void Brick::draw(Graphics& gfx) const
{
	if (!destroyed) {
		rectangle.drawWithOffset(gfx, color);
	}
}

void Brick::destroy()
{
	destroyed = true;
}

bool Brick::isDestroyed() const
{
	return destroyed;
}

const MyRectangle& Brick::getRectangle() const
{
	return rectangle;
}
