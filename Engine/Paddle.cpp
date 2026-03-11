#include "Paddle.h"

Paddle::Paddle(const Rectangle2D& centralRect) :
	leftRect({ centralRect.GetTopLeftCorner().x - 15.0f, centralRect.GetTopLeftCorner().y + 3.0f }, { 15.0f, centralRect.GetHeight() - 6.0f }, Colors::White),
	rightRect({ centralRect.GetTopLeftCorner().x + centralRect.GetWidth() , centralRect.GetTopLeftCorner().y + 3.0f }, { 15.0f, centralRect.GetHeight() - 6.0f }, Colors::White),
	centralRect(centralRect)
{
}

void Paddle::Move(const float horizontalMovement)
{
	const Vec2D& deltaMovementVector = Vec2D{ horizontalMovement, 0.0f } * speed;
	Shift(deltaMovementVector);
	Clamp(deltaMovementVector);
}

void Paddle::Render(Graphics& gfx) const
{
	gfx.DrawRect(centralRect);
	gfx.DrawRect(leftRect);
	gfx.DrawRect(rightRect);
}

const Rectangle2D& Paddle::GetLeftRect() const
{
	return leftRect;
}

const Rectangle2D& Paddle::GetRightRect() const
{
	return rightRect;
}

const Rectangle2D& Paddle::GetCentralRect() const
{
	return centralRect;
}

void Paddle::Clamp(const Vec2D& deltaMovementVector)
{
	if ((leftRect.GetTopLeftCorner() + deltaMovementVector).x < 0 || rightRect.GetTopLeftCorner().x + rightRect.GetWidth() > Graphics::ScreenWidth) {
		Shift(deltaMovementVector * -1);
	}
}

void Paddle::Shift(const Vec2D& shift) {
	leftRect.Shift(shift);
	rightRect.Shift(shift);
	centralRect.Shift(shift);
}



