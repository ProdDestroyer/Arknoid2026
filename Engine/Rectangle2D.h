#pragma once
#include "Vec2D.h"
#include "Graphics.h"
class Rectangle2D {
public:
	Rectangle2D(const Vec2D& topLeftCorner, const Vec2D& dimensions, const Color& color);
	Rectangle2D() = default;
	const Vec2D& GetTopLeftCorner() const;
	void Render(Graphics& gfx) const;
	const float GetWidth() const;
	const float GetHeight() const;
	const Vec2D& GetCenter() const;
private:
	Vec2D topLeftCorner;
	Vec2D dimensions;
	Color color;
};