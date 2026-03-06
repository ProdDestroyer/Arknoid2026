#include "Rectangle2D.h"

Rectangle2D::Rectangle2D(const Vec2D& topLeftCorner, const Vec2D& dimensions, const Color& color) :
	topLeftCorner(topLeftCorner),
	dimensions(dimensions),
	color(color)
{

}

void Rectangle2D::Render(Graphics& gfx) const
{
	gfx.DrawRect(int( topLeftCorner.x ), int( topLeftCorner.y ), int( dimensions.x ), int( dimensions.y ), color);
}

const float Rectangle2D::GetWidth() const
{
	return dimensions.x;
}

const float Rectangle2D::GetHeight() const
{
	return dimensions.y;
}
