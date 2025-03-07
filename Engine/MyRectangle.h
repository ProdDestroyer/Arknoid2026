#pragma once
#include "Vec2D.h"
#include "Graphics.h"
#include "Colors.h"
class MyRectangle {
public:
	MyRectangle() = default;
	MyRectangle(const Vec2D& topLeftCorner, const Vec2D& dimensions);
	void draw(Graphics& gfx, const Color& color) const;
	void drawWithOffset(Graphics& gfx, const Color& color) const;
	bool Intersects(const MyRectangle& targetRectangle) const;
	const Vec2D& getCorner() const;
	const Vec2D& getDimensions() const;
	void moveX(const float dx);
private:
	static constexpr int offset = 2;
	Vec2D corner;
	Vec2D dimensions;
};
