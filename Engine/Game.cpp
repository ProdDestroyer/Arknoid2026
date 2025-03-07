/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2D(20.0f, 20.0f), Vec2D(30.0f, 30.0f)),
	paddle(MyRectangle(Vec2D(350, 500), Vec2D(70, 25)))
{
	int index = 0;
	Vec2D dimensions(brickWidth, brickHeight);
	for (int j = 0; j < heightInBricks; j++) {
		for (int i = 0; i < widthInBricks; i++) {
			bricks[index++] = Brick(Vec2D(initialX + brickWidth * i, initialY + brickHeight * j), dimensions, bricksColors[j % 5]);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float dt = ts.getDelta();
	while (dt > 0) {
		const float subdt = std::min(0.0025f, dt);
		UpdateModel(subdt);
		dt -= subdt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(const float dt)
{
	paddle.move(wnd.kbd, dt);
	ball.moveX(dt);
	bool collided = false;
	if (checkBricksCollision()) {
		ball.rebounceX();
		collided = true;
	}
	ball.moveY(dt);
	if (!collided && checkBricksCollision()) {
		ball.rebounceY();
	}
	ball.intersectsPaddle(paddle.getRectangle());
}

bool Game::checkBricksCollision()
{
	int index = -1;
	float lessSqrdDistance = std::numeric_limits<float>::max();
	int counter = 0;
	for (int i = 0; i < widthInBricks * heightInBricks; i++) {
		float currentSqrdDistance = (ball.getRectangle().getCenter() - bricks[i].getRectangle().getCenter()).lengthSqrd();
		if (!bricks[i].isDestroyed() && ball.intersects(bricks[i].getRectangle()) && currentSqrdDistance < lessSqrdDistance) {
			lessSqrdDistance = currentSqrdDistance;
			index = i;
			counter += 1;
		}
	}
	if (index > -1) {
		bricks[index].destroy();
	}
	return index > -1;
}

void Game::ComposeFrame()
{
	for (const Brick& b : bricks) {
		b.draw(gfx);
	}
	paddle.draw(gfx);
	ball.draw(gfx);

}
