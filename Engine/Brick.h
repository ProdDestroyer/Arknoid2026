#pragma once
#include "Vec2D.h"
#include "Colors.h"
#include "MyRectangle.h"
#include "Graphics.h"
class Brick
{
public:
	Brick() = default;
	Brick(const Vec2D& topLeftCorner, const Vec2D& dimensions, const Color& color);
	void draw(Graphics& gfx) const;
private:

	MyRectangle rectangle;
	Color color;
};

