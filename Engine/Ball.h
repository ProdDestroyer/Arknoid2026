#pragma once
#include "Vec2D.h"
#include "Graphics.h"
#include "Sound.h"
#include "MyRectangle.h"
class Ball {
public:
	Ball(Vec2D& center, Vec2D& vel);

	const Vec2D& getCenter() const;
	const Vec2D& getVel() const;
	void move(const float dt);
	void draw(Graphics& gfx) const;
	MyRectangle getRectangle() const;
private:
	static constexpr float radius = 7.0f;
	Vec2D center;
	Vec2D vel;
	Sound soundPad;
	Vec2D clampX();
	Vec2D clampY();
};