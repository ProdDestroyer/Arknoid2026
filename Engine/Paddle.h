#pragma once
#include "MyRectangle.h"
#include "Graphics.h"
#include "Colors.h"
#include "Vec2D.h"
#include "Keyboard.h"
class Paddle
{
public:
	Paddle(const MyRectangle& rectangle);
	void draw(Graphics& gfx) const;
	void move(const Keyboard& kbd, const float dt);

private:
	MyRectangle rectangle;
	static constexpr float speed = 200.0f;
};

