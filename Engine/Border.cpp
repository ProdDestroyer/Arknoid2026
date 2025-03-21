#include "Border.h"

Border::Border(MyRectangle& rectangle, const float offset) :
	rectangle(rectangle)
{
	this->offset = offset;
}

void Border::draw(Graphics& gfx) const
{
	//Inner
	//Top
	gfx.DrawRect(rectangle.getCorner().x + 2.0f * offset, rectangle.getCorner().y + offset, rectangle.getDimensions().x - 2.0f * offset, offset, colors[3]);
	gfx.drawHalfSquareTopRight(rectangle.getCorner().x + offset, rectangle.getCorner().y + offset, rectangle.getCorner().x + 2.0f * offset, rectangle.getCorner().y + 2.0f * offset, colors[3]);
	gfx.drawHalfSquareTopLeft(rectangle.getCorner().x + rectangle.getDimensions().x, rectangle.getCorner().y + offset, rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y + 2.0f * offset, colors[3]);
	//Bottom
	gfx.DrawRect(rectangle.getCorner().x + 2.0f * offset, rectangle.getCorner().y + rectangle.getDimensions().y, rectangle.getDimensions().x - 2.0 * offset, offset, colors[4]);
	gfx.drawHalfSquareBottomRight(rectangle.getCorner().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y, rectangle.getCorner().x + 2.0f * offset, rectangle.getCorner().y + rectangle.getDimensions().y + offset, colors[4]);
	gfx.drawHalfSquareBottomLeft(rectangle.getCorner().x + rectangle.getDimensions().x, rectangle.getCorner().y + rectangle.getDimensions().y, rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y + offset, colors[4]);
	//Left
	gfx.DrawRect(rectangle.getCorner().x + offset, rectangle.getCorner().y + 2.0f * offset, offset, rectangle.getDimensions().y - offset * 2.0f, colors[0]);
	gfx.drawHalfSquareBottomLeft(rectangle.getCorner().x + offset, rectangle.getCorner().y + offset, rectangle.getCorner().x + 2.0f * offset, rectangle.getCorner().y + 2.0f * offset, colors[0]);
	gfx.drawHalfSquareTopLeft(rectangle.getCorner().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y, rectangle.getCorner().x + 2.0f * offset, rectangle.getCorner().y + rectangle.getDimensions().y + offset, colors[0]);
	//Right
	gfx.DrawRect(rectangle.getCorner().x + rectangle.getDimensions().x, rectangle.getCorner().y + 2.0f * offset, offset, rectangle.getDimensions().y - offset * 2.0f, colors[1]);
	gfx.drawHalfSquareBottomRight(rectangle.getCorner().x + rectangle.getDimensions().x, rectangle.getCorner().y + offset, rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y + 2.0f * offset, colors[1]);
	gfx.drawHalfSquareTopRight(rectangle.getCorner().x + rectangle.getDimensions().x, rectangle.getCorner().y + rectangle.getDimensions().y, rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y + offset, colors[1]);
	//Outter
	//Top
	gfx.DrawRect(rectangle.getCorner().x + offset, rectangle.getCorner().y, rectangle.getDimensions().x, offset, colors[2]);
	gfx.drawHalfSquareTopRight(rectangle.getCorner().x , rectangle.getCorner().y, rectangle.getCorner().x + offset, rectangle.getCorner().y + offset, colors[2]);
	gfx.drawHalfSquareTopLeft(rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y , rectangle.getCorner().x + rectangle.getDimensions().x + 2.0f*offset, rectangle.getCorner().y + offset, colors[2]);
	//Bottom
	gfx.DrawRect(rectangle.getCorner().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y + offset, rectangle.getDimensions().x, offset, colors[5]);
	gfx.drawHalfSquareBottomRight(rectangle.getCorner().x, rectangle.getCorner().y + rectangle.getDimensions().y + offset, rectangle.getCorner().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y + 2.0f*offset, colors[5]);
	gfx.drawHalfSquareBottomLeft(rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y + offset, rectangle.getCorner().x + rectangle.getDimensions().x + 2.0f*offset, rectangle.getCorner().y + rectangle.getDimensions().y + 2.0f*offset, colors[5]);
	//Left
	gfx.DrawRect(rectangle.getCorner().x, rectangle.getCorner().y + offset, offset, rectangle.getDimensions().y, colors[1]);
	gfx.drawHalfSquareBottomLeft(rectangle.getCorner().x, rectangle.getCorner().y, rectangle.getCorner().x + offset, rectangle.getCorner().y + offset, colors[1]);
	gfx.drawHalfSquareTopLeft(rectangle.getCorner().x, rectangle.getCorner().y + rectangle.getDimensions().y + offset, rectangle.getCorner().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y + 2.0f*offset, colors[1]);
	//Right
	gfx.DrawRect(rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y + offset, offset, rectangle.getDimensions().y, colors[0]);
	gfx.drawHalfSquareBottomRight(rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y, rectangle.getCorner().x + rectangle.getDimensions().x + 2.0f*offset, rectangle.getCorner().y + offset, colors[0]);
	gfx.drawHalfSquareTopRight(rectangle.getCorner().x + rectangle.getDimensions().x + offset, rectangle.getCorner().y + rectangle.getDimensions().y + offset, rectangle.getCorner().x + rectangle.getDimensions().x + 2.0f*offset, rectangle.getCorner().y + rectangle.getDimensions().y + 2.0f*offset, colors[0]);
}

const MyRectangle Border::boundariesRectangle() const
{
	return MyRectangle(Vec2D(rectangle.getCorner().x + 2.0f*offset, rectangle.getCorner().y + 2.0f*offset), Vec2D(rectangle.getDimensions().x - 2.0f * offset, rectangle.getDimensions().y - offset * 2.0f));
}
