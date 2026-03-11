#pragma once
#include "Vec2D.h"
#include "Colors.h"
class Rectangle2D {
public:
	Rectangle2D(const Vec2D& topLeftCorner, const Vec2D& dimensions, const Color& color);
	Rectangle2D() = default;
	const Vec2D& GetTopLeftCorner() const;
	const float GetWidth() const;
	const float GetHeight() const;
	const Vec2D& GetCenter() const;
	const Color& GetColor() const;
	void Shift(const Vec2D& shift);
	void SetTopLeftCorner(const Vec2D& newTopLeftCorner);
private:
	Vec2D topLeftCorner;
	Vec2D dimensions;
	Color color;
};