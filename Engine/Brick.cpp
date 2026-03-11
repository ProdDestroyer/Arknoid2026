#include "Brick.h"

Brick::Brick(const Rectangle2D& rectangle) :
	rectangle(rectangle)
{
	alive = true;
}

void Brick::Render(Graphics& gfx) const
{
	gfx.DrawRect(rectangle);
}

const bool Brick::isAlive() const
{
	return alive;
}

const Rectangle2D& Brick::GetRectangle() const
{
	return rectangle;
}
