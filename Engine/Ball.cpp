#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2D ballCenter) :
	center(ballCenter),
	direction(1.0f, -2.0f)
{
	direction.Normalize();
}

void Ball::Move(const float dt)
{
	center += direction * ( dt * speed);
}

void Ball::Render(Graphics& gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}
