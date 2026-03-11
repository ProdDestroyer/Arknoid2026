#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2D ballCenter) :
	center(ballCenter),
	direction(Vec2D( 1.0f, 2.0f ).Normalized()),
	soundPad(L"Sounds\\arkpad.wav")
{
	direction.Normalize();
}

void Ball::Move(const float dt)
{
	center += direction * ( dt * speed);
	CheckWallsCollision();
}

void Ball::CheckWallsCollision()
{
	if (center.x + radius >= Graphics::ScreenWidth) {
		center.x = Graphics::ScreenWidth - radius;
		direction.x *= -1;
		soundPad.Play();

	} else if (center.x - radius < 0) {
		center.x = radius;
		direction.x *= -1;
		soundPad.Play();
	 }

	if (center.y + radius >= Graphics::ScreenHeight ) {
		center.y = Graphics::ScreenHeight - radius;
		direction.y *= -1;
		soundPad.Play();
	}
	else if (center.y - radius < 0) {
		center.y = radius;
		direction.y *= -1;
		soundPad.Play();
	}
}

void Ball::Render(Graphics& gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

const Vec2D& Ball::GetDirection() const
{
	return direction;
}

const Vec2D& Ball::GetCenter() const
{
	return center;
}

void Ball::Shift(const Vec2D& shift)
{
	center += shift;
}

void Ball::InvertXMovement()
{
	direction.x *= -1;
}

void Ball::InvertYMovement()
{
	direction.y *= -1;
}

void Ball::SetDirection(const Vec2D& newDirection)
{
	direction = newDirection.Normalized();
}
