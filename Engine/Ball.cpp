#include "Ball.h"
#include "SpriteCodex.h"
#include <cmath>

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

void Ball::move(const float dt)
{
	center += vel.normalized() * dt * speed;
	Vec2D centerBeforeClamp = center;
	Vec2D velBefore = vel;
	center = clampX();
	vel.x *= (getCenter() == centerBeforeClamp) ? 1 : -1;

	centerBeforeClamp = center;
	center = clampY();
	vel.y *= (getCenter() == centerBeforeClamp) ? 1 : -1;

	if (vel != velBefore) {
		removeColdDown();
		soundPad.Play();
	}
}


void Ball::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

MyRectangle Ball::getRectangle() const
{
	return MyRectangle(Vec2D(center.x - radius, center.y - radius), Vec2D(radius * 2.0f, radius * 2.0f));
}

void Ball::rebounce(const MyRectangle& target) {
	if ((getCenter().x > target.getCorner().x + target.getDimensions().x || getCenter().x < target.getCorner().x) && !(std::signbit(getCenter().x - target.getCenter().x) == std::signbit(vel.x))) {
		rebounceX();
	}
	else if (std::signbit(getCenter().x - target.getCenter().x) == std::signbit(vel.x)) {
		rebounceY();
	}
	else {
		rebounceY();
	}
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
	if (target.Intersects(getRectangle()) && !coldDown) {
		paddleCollisionResolution(target);
		putOnColdDown();
	}
}

void Ball::putOnColdDown()
{
	coldDown = true;
}

void Ball::removeColdDown()
{
	coldDown = false;
}

void Ball::paddleCollisionResolution(const MyRectangle& target)
{
	Vec2D referenceVec(target.getCorner().x + (target.getDimensions().x / 2.0f), target.getCorner().y);

	if (getCenter().x < target.getCorner().x + (target.getDimensions().x / 2.0f)) {
		const float deltaX = target.getCorner().x + (target.getDimensions().x / 2.0f) - getCenter().x;
		const float xFactor = (target.getDimensions().x / 2.0f) - deltaX;
		const float yDelta = std::max<float>(10.0f, deltaX);
		const float yFactor = target.getCorner().y - yDelta;
		Vec2D rebounceVector(target.getCorner().x + xFactor, yFactor);

		Vec2D newVel = (rebounceVector - referenceVec).normalized();
		this->vel = newVel;
	}
	else {
		const float deltaX = target.getCorner().x + target.getDimensions().x - getCenter().x;
		const float yDelta = std::max<float>(10.0f, deltaX);
		const float yFactor = target.getCorner().y - yDelta;
		Vec2D rebounceVector = (Vec2D(getCenter().x, yFactor) - referenceVec).normalized() * 100;
		this->vel = rebounceVector;
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
