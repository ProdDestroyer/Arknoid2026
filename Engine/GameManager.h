#pragma once
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
class GameManager {
public:
	GameManager();
	void Move(const float dt, const float paddleMovementDelta);
	void Render(Graphics& gfx);

private:
	void BuildBricks();
	void RenderBricks(Graphics& gfx) const;
	void CheckBricksCollision();
	void CheckBallRectangleCollision(const Rectangle2D& targetRectangle);
	void CheckBricksLateralCollision(const Vec2D& currentBrickTopLeftCorner, const Vec2D& currentBrickBottomRightCorner, const Vec2D& currentBrickBottomLeftCorner);
	void CheckPaddleCollision();
private:
	Ball ball;
	Paddle paddle;
	static constexpr int bricksZoneHeight = Graphics::ScreenHeight / 5;
	static constexpr int bricksZoneWidth = int(Graphics::ScreenWidth * 8.0f / 10.0f);
	static constexpr float horizontalMargin = (Graphics::ScreenWidth - bricksZoneWidth) / 2.0f;
	static constexpr float verticalMargin = Graphics::ScreenWidth / 30.0f;
	static constexpr int bricksAmountHorizontally = 10;
	static constexpr int bricksAmountVertically = 4;
	static constexpr int horizontalGap = 30;
	static constexpr int verticalGap = 20;
	static constexpr float brickWidth =  (bricksZoneWidth - (horizontalGap * (bricksAmountHorizontally - 1))) / bricksAmountHorizontally;
	static constexpr float brickHeight = (bricksZoneHeight - (verticalGap * (bricksAmountVertically - 1))) / bricksAmountVertically;
	Brick bricks[bricksAmountVertically * bricksAmountHorizontally];
	bool gameOver = false;
};