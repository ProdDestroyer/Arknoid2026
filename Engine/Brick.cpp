#include "Brick.h"

Brick::Brick(const Vec2D& topLeftCorner, const Vec2D& dimensions, const Color& color) :
	rectangle(topLeftCorner, dimensions)
{
	this->color = color;
}

void Brick::draw(Graphics& gfx) const
{
	rectangle.drawWithOffset(gfx, color);
}
