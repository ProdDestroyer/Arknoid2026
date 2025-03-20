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
	void rebounce(const MyRectangle& target);
	void rebounceY();
	void rebounceX();
	bool intersects(const MyRectangle& target) const;
	void intersectsPaddle(const MyRectangle& target);
	void putOnColdDown();
	void removeColdDown();
private:
	void paddleCollisionResolution(const MyRectangle& target);
	bool coldDown = false;
	static constexpr float radius = 7.0f;
	static constexpr float speed = 320.0f;
	Vec2D center;
	Vec2D vel;
	Sound soundPad;
	Vec2D clampX();
	Vec2D clampY();
};