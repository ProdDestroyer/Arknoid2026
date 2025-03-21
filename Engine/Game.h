/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Vec2D.h"
#include "Ball.h"
#include "TimeStamp.h"
#include "Brick.h"
#include "Paddle.h"
#include "MyRectangle.h"
#include "Border.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(const float dt);
	int checkBricksCollision();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	Ball ball;
	TimeStamp ts;
	static constexpr int widthInBricks = 10;
	static constexpr int heightInBricks = 8;
	static constexpr float brickWidth = 50;
	static constexpr float brickHeight = 25;
	static constexpr float initialX = (Graphics::ScreenWidth - widthInBricks * brickWidth) / 2;
	static constexpr float initialY = Graphics::ScreenHeight / 10;
	static constexpr int nBodyColors = 5;
	static constexpr Color bricksColors[nBodyColors] = {
	{ 255, 0, 0 },   // Red
	{ 255, 165, 0 }, // Orange
	{ 0, 0, 255 },   // Blue
	{ 128, 0, 128 },  // Purple
	{0, 255, 255 } // Cyan
	};

	Brick bricks[widthInBricks * heightInBricks];
	Paddle paddle;
	Border border;
	/********************************/
	/*  User Variables              */
	/********************************/
};