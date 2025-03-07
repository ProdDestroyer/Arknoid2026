#include "Paddle.h"

Paddle::Paddle(const MyRectangle& rectangle) :
	rectangle(rectangle)
{
}

void Paddle::draw(Graphics& gfx) const
{
	rectangle.draw(gfx, Colors::Red);
	const float percentagePadding = rectangle.getDimensions().x * 0.2f;
	const MyRectangle innerRectangle(Vec2D(rectangle.getCorner().x + percentagePadding, rectangle.getCorner().y), Vec2D(rectangle.getDimensions().x - percentagePadding * 2, rectangle.getDimensions().y));
	innerRectangle.draw(gfx, Colors::White);

}

void Paddle::move(const Keyboard& kbd, const float dt)
{
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		rectangle.moveX(speed * dt);
	}
	else if(kbd.KeyIsPressed(VK_LEFT)) {
		rectangle.moveX(-speed * dt);
	}
}
