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
	ball(Vec2D(200.0f, 400.0f), Vec2D(1.0f, -1.0f)),
	paddle(MyRectangle(Vec2D(350, 500), Vec2D(70, 12.5f))),
	border(MyRectangle(Vec2D(initialX - 14.0f, initialY - 14.0f), Vec2D(widthInBricks * brickWidth + 14.0f, 500.0f)), 7.0f)
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
	paddle.move(border.boundariesRectangle(), wnd.kbd, dt);
	ball.move(border.boundariesRectangle(), dt);
	bool collided = false;
	const int collisionIndex = checkBricksCollision();
	if (collisionIndex > -1) {
		ball.rebounce(bricks[collisionIndex].getRectangle());
	}

	ball.intersectsPaddle(paddle.getRectangle());
}

int Game::checkBricksCollision()
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
		ball.removeColdDown();
	}

	return index;
}

void Game::ComposeFrame()
{
	border.draw(gfx);
	for (const Brick& b : bricks) {
		b.draw(gfx);
	}
	paddle.draw(gfx);
	ball.draw(gfx);
	//border.boundariesRectangle().draw(gfx, Colors::Cyan);
	//rgb(0 27 134) inner left
	//rgb(9 58 236) outter left
	//rgb(1 46 201) outter top
	//rgb(0 37 169) inner top
	//rgb(1 33 146) inner bottom
	//rgb(0 26 122) outter bottom

}
