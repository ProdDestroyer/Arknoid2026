#pragma once
#include "Rectangle2D.h"
class Brick {
public:
	Brick() = default;
	Brick(const Rectangle2D& rectangle);
	void Render(Graphics& gfx) const;
	const bool isAlive() const;
private:
	Rectangle2D rectangle;
	bool alive = false;
};