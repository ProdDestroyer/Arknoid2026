#pragma once
#include "Vec2D.h"
#include "Graphics.h"
class Ball {
public:
	Ball(Vec2D ballCenter);
	void Move(const float dt);
	void Render(Graphics& gfx) const;
	static constexpr float radius = 14.0f;
	static constexpr float speed = 60.0f;
private:
	Vec2D center;
	Vec2D direction;
};