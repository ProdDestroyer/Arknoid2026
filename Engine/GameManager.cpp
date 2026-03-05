#include "GameManager.h"

GameManager::GameManager() :
	ball({ Graphics::ScreenWidth / 2.0f, Graphics::ScreenHeight * 9.0f / 10.0f})
{
}

void GameManager::Move(const float dt)
{
	ball.Move(dt);
}

void GameManager::Render(Graphics& gfx) const
{
	ball.Render(gfx);
}
