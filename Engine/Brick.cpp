#include "Brick.h"

Brick::Brick(const Rectangle2D& rectangle) :
	rectangle(rectangle)
{
	alive = true;
}

void Brick::Render(Graphics& gfx) const
{
	rectangle.Render(gfx);
}

const bool Brick::isAlive() const
{
	return alive;
}
