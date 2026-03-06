#pragma once
#include "Vec2D.h"
#include "Graphics.h"
#include "Sound.h"
class Ball {
public:
	Ball(Vec2D ballCenter);
	void Move(const float dt);
	void CheckWallsCollision();
	void Render(Graphics& gfx) const;
	static constexpr float radius = 7.0f;
	static constexpr float speed = 240.0f;
private:
	Vec2D center;
	Vec2D direction;
	Sound soundPad;
};