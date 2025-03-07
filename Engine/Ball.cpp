#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2D& center, Vec2D& vel) :
	center(center),
	vel(vel),
	soundPad(L"Sounds\\arkpad.wav")
{
}

const Vec2D& Ball::getCenter() const
{

	return center;
}

const Vec2D& Ball::getVel() const
{
	return vel;
}

void Ball::moveX(const float dt)
{
	center += Vec2D((vel * dt).x, 0.0f);
	Vec2D centerBeforeClamp = center;
	Vec2D velBefore = vel;
	center = clampX();
	vel.x *= (getCenter() == centerBeforeClamp) ? 1 : -1;

	if (vel != velBefore) {
		soundPad.Play();
	}
}

void Ball::moveY(const float dt)
{
	center += Vec2D(0.0f, (vel * dt).y);
	Vec2D centerBeforeClamp = center;
	Vec2D velBefore = vel;
	center = clampY();
	vel.y *= (getCenter() == centerBeforeClamp) ? 1 : -1;

	if (vel != velBefore) {
		soundPad.Play();
	}
}

void Ball::draw(Graphics& gfx) const
{
	gfx.DrawRect(center.x - radius, center.y - radius, radius * 2.0f, radius * 2.0f, Colors::White);
	SpriteCodex::DrawBall(center, gfx);
}

MyRectangle Ball::getRectangle() const
{
	return MyRectangle(Vec2D(center.x - radius, center.y -radius), Vec2D(radius * 2.0f, radius * 2.0f));
}

void Ball::rebounceX()
{
	vel.x *= -1;
}

void Ball::rebounceY()
{
	vel.y *= -1;
}

bool Ball::intersects(const MyRectangle& target) const
{
	return target.Intersects(getRectangle());

}

void Ball::intersectsPaddle(const MyRectangle& target)
{
	if (target.Intersects(getRectangle())) {
		rebounceY();
	}

}

Vec2D Ball::clampX()
{
	return (center.x - radius < 0) ? Vec2D(radius, center.y) : (center.x + radius > Graphics::ScreenWidth - 1) ? Vec2D(Graphics::ScreenWidth - 1 - radius, center.y) : center;
}

Vec2D Ball::clampY()
{
	return (center.y - radius < 0) ? Vec2D(center.x, radius) : (center.y + radius > Graphics::ScreenHeight - 1) ? Vec2D(center.x, Graphics::ScreenHeight - 1 - radius) : center;
}
