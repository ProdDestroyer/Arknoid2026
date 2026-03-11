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
	const Vec2D& GetDirection() const;
	const Vec2D& GetCenter() const;
	void Shift(const Vec2D& shift);
	static constexpr float radius = 7.0f;
	static constexpr float speed = 280.0f;
	void InvertXMovement();
	void InvertYMovement();
	void SetDirection(const Vec2D& newDirection);
private:
	Vec2D center;
	Vec2D direction;
	Sound soundPad;
};