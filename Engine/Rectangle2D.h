#pragma once
#include "Vec2D.h"
#include "Graphics.h"
class Rectangle2D {
public:
	Rectangle2D(const Vec2D& topLeftCorner, const Vec2D& dimensions, const Color& color);
	Rectangle2D() = default;
	void Render(Graphics& gfx) const;
	const float GetWidth() const;
	const float GetHeight() const;
private:
	Vec2D topLeftCorner;
	Vec2D dimensions;
	Color color;
};