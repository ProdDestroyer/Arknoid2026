#include "MyRectangle.h"

MyRectangle::MyRectangle(const Vec2D& topLeftCorner, const Vec2D& dimensions)
{
	this->corner = topLeftCorner;
	this->dimensions = dimensions;
}

void MyRectangle::draw(Graphics& gfx, const Color& color) const
{
	gfx.DrawRect(int(corner.x), int(corner.y), int(dimensions.x), int(dimensions.y), color);
}

void MyRectangle::drawWithOffset(Graphics& gfx, const Color& color) const
{
	gfx.DrawRect(int(corner.x + offset), int(corner.y + offset), int(dimensions.x - offset), int(dimensions.y - offset), color);
}

bool MyRectangle::Intersects(const MyRectangle& targetRectangle) const
{
	const int targetRightLimit = int(targetRectangle.corner.x + targetRectangle.dimensions.x);
	const int targetBottomLimit = int(targetRectangle.corner.y + targetRectangle.dimensions.y);
	const int targetLeftLimit = int(targetRectangle.corner.x);
	const int targetTopLimit = int(targetRectangle.corner.y);
	return (targetLeftLimit <= corner.x + dimensions.x && targetRightLimit >= corner.x && targetTopLimit <= corner.y + dimensions.y && targetBottomLimit >= corner.y);
}

const Vec2D& MyRectangle::getCorner() const
{
	return corner;
}

const Vec2D& MyRectangle::getDimensions() const
{
	return dimensions;
}

void MyRectangle::moveX(const float dx)
{
	corner.x = (corner.x + dimensions.x + dx < Graphics::ScreenWidth) ? corner.x + dx : Graphics::ScreenWidth - dimensions.x;
	corner.x = (corner.x > 0) ? corner.x : 0;
}

