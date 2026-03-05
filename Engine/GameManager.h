#pragma once
#include "Ball.h"
#include "Vec2D.h"
class GameManager {
public:
	GameManager();
	void Move(const float dt);
	void Render(Graphics& gfx) const;
private:
	Ball ball;
};
