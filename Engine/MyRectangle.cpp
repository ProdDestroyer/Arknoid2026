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
	gfx.DrawRect(int(corner.x + offset), int(corner.y + offset), int(dimensions.x - 2.0f * offset), int(dimensions.y - 2.0f * offset), color);
	const int shadowOffset = int((dimensions.x * dimensions.x + dimensions.y * dimensions.y) / 750.0f);

	//RightShadow
	Color rightShadowColor = {
			static_cast<unsigned char>(std::max<int>(0, int(color.GetR()) - 75)),
			static_cast<unsigned char>(std::max<int>(0, int(color.GetG()) - 75)),
			static_cast<unsigned char>(std::max<int>(0, int(color.GetB()) - 75))
	};
	gfx.DrawRect(int(corner.x + dimensions.x - offset - shadowOffset), int(corner.y + offset + shadowOffset), shadowOffset, int(dimensions.y - 2.0f * offset - 2.0f * shadowOffset), rightShadowColor);
	gfx.drawHalfSquareBottomRight(int(corner.x + dimensions.x - offset - shadowOffset), int(corner.y + offset), int(corner.x + dimensions.x - offset), int(corner.y + offset + shadowOffset), rightShadowColor);
	gfx.drawHalfSquareTopRight(int(corner.x + dimensions.x - offset - shadowOffset), int(corner.y + dimensions.y - offset - shadowOffset), int(corner.x + dimensions.x - offset), int(corner.y + dimensions.y - offset), rightShadowColor);
	//BottomShadow
	Color bottomShadowColor = {
			static_cast<unsigned char>(std::max<int>(0, int(color.GetR()) - 45)),
			static_cast<unsigned char>(std::max<int>(0, int(color.GetG()) - 45)),
			static_cast<unsigned char>(std::max<int>(0, int(color.GetB()) - 45))
	};
	gfx.DrawRect(int(corner.x + offset + shadowOffset), int(corner.y + dimensions.y - offset - shadowOffset), int(dimensions.x - 2.0f * offset - 2.0f * shadowOffset), shadowOffset, bottomShadowColor);
	gfx.drawHalfSquareBottomRight(int(corner.x + offset), int(corner.y + dimensions.y - offset - shadowOffset), int(corner.x + offset + shadowOffset), int(corner.y + dimensions.y - offset), bottomShadowColor);
	gfx.drawHalfSquareBottomLeft(int(corner.x + dimensions.x - offset - shadowOffset), int(corner.y + dimensions.y - offset - shadowOffset), int(corner.x + dimensions.x - offset), int(corner.y + dimensions.y - offset), bottomShadowColor);
	//LeftShadow
	Color leftShadowColor = {
			static_cast<unsigned char>(std::min<int>(255, int(color.GetR()) + 20)),
			static_cast<unsigned char>(std::min<int>(255, int(color.GetG()) + 20)),
			static_cast<unsigned char>(std::min<int>(255, int(color.GetB()) + 20))
	};
	gfx.DrawRect(int(corner.x + offset),int(corner.y + offset + shadowOffset),shadowOffset,int(dimensions.y - 2.0f * (offset + shadowOffset)),leftShadowColor);
	gfx.drawHalfSquareBottomLeft(int(corner.x + offset), int(corner.y + offset), int(corner.x + offset + shadowOffset), int(corner.y + offset + shadowOffset), leftShadowColor);
	gfx.drawHalfSquareTopLeft(int(corner.x + offset), int(corner.y + dimensions.y - offset - shadowOffset), int(corner.x + offset + shadowOffset), int(corner.y + dimensions.y - offset), leftShadowColor);
	//TopShadow
	Color topShadowColor = {
			static_cast<unsigned char>(std::max<int>(0, int(color.GetR()) - 30)),
			static_cast<unsigned char>(std::max<int>(0, int(color.GetG()) - 30)),
			static_cast<unsigned char>(std::max<int>(0, int(color.GetB()) - 30))
	};

	gfx.DrawRect(int(corner.x + offset + shadowOffset), int(corner.y + offset), int(dimensions.x - 2.0f * offset - 2.0f * shadowOffset), shadowOffset, topShadowColor);
	gfx.drawHalfSquareTopRight(int(corner.x + offset), int(corner.y + offset), int(corner.x + offset + shadowOffset), int(corner.y + offset + shadowOffset), topShadowColor);
	gfx.drawHalfSquareTopLeft(int(corner.x + dimensions.x - offset - shadowOffset), int(corner.y + offset), int(corner.x + dimensions.x - offset), int(corner.y + offset + shadowOffset), topShadowColor);
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

void MyRectangle::moveX(const MyRectangle& boundaryRect, const float dx)
{
	const int rightLimit = boundaryRect.getCorner().x + boundaryRect.getDimensions().x;
	const int leftLimit = boundaryRect.getCorner().x;
	corner.x = (corner.x + dimensions.x + dx < rightLimit) ? corner.x + dx : rightLimit - dimensions.x;
	corner.x = (corner.x > leftLimit) ? corner.x : leftLimit;
}

Vec2D MyRectangle::getCenter() const
{
	return Vec2D(corner.x + dimensions.x / 2.0f, corner.y + dimensions.y / 2.0f);
}

