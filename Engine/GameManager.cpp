#include "GameManager.h"

GameManager::GameManager() :
	ball({ Graphics::ScreenWidth / 2.0f, Graphics::ScreenHeight * 9.0f / 10.0f })
{
	for (int j = 0; j < bricksAmountVertically; j++) {
		for (int i = 0; i < bricksAmountHorizontally; i++) {
			bricks[j * bricksAmountHorizontally + i] = Brick(Rectangle2D(Vec2D(horizontalMargin + (i * (horizontalGap + brickWidth)), verticalMargin + j * (verticalGap + brickHeight)), Vec2D(brickWidth, brickHeight), Colors::Magenta));
		}
	}
}

void GameManager::Move(const float dt)
{
	ball.Move(dt);
}

void GameManager::Render(Graphics& gfx) const
{
	RenderBricks(gfx);
	ball.Render(gfx);

}

void GameManager::BuildBricks()
{

}

void GameManager::RenderBricks(Graphics& gfx) const
{
	for (int i = 0; i < bricksAmountVertically * bricksAmountHorizontally; i++) {
		bricks[i].Render(gfx);
	}
}
