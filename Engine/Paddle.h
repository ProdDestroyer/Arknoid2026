#pragma once
#include "Rectangle2D.h"
#include "Graphics.h"
class Paddle {
public:
	Paddle(const Rectangle2D& centralRect);
	void Move(const float horizontalMovement);
	void Render(Graphics& gfx) const;
	const Rectangle2D& GetLeftRect() const;
	const Rectangle2D& GetRightRect() const;
	const Rectangle2D& GetCentralRect() const;
private:
	void Clamp(const Vec2D& deltaMovementVector);
	void Paddle::Shift(const Vec2D& shift);
private:
	static constexpr float speed = 350.0f;
	Rectangle2D leftRect;
	Rectangle2D rightRect;
	Rectangle2D centralRect;
};
