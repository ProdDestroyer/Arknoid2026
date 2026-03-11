#include "GameManager.h"
#include <cmath>

GameManager::GameManager() :
	ball({ Graphics::ScreenWidth / 2.0f,  Graphics::ScreenHeight / 4.0f })
{
	for (int j = 0; j < bricksAmountVertically; j++) {
		for (int i = 0; i < bricksAmountHorizontally; i++) {
			bricks[j * bricksAmountHorizontally + i] = Brick(Rectangle2D(Vec2D(horizontalMargin + (i * (horizontalGap + brickWidth)), verticalMargin + j * (verticalGap + brickHeight)), Vec2D(brickWidth, brickHeight), Colors::Magenta));
		}
	}
}

void GameManager::Move(const float dt)
{
	if (!gameOver) {
		ball.Move(dt);
		CheckBricksCollision();
	}
}

void GameManager::Render(Graphics& gfx)
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

void GameManager::CheckBricksCollision()
{
	for (int i = 0; i < bricksAmountVertically * bricksAmountHorizontally; i++) {

		const Vec2D currentBrickTopLeftCorner = bricks[i].GetRectangle().GetTopLeftCorner();
		const Vec2D currentBrickTopRightCorner = Vec2D(currentBrickTopLeftCorner.x + brickWidth, currentBrickTopLeftCorner.y);
		const Vec2D currentBrickBottomLeftCorner = Vec2D(currentBrickTopLeftCorner.x, currentBrickTopLeftCorner.y + brickHeight);
		const Vec2D currentBrickBottomRightCorner = Vec2D(currentBrickTopRightCorner.x, currentBrickBottomLeftCorner.y);

		Vec2D currentBrickCorners[4] = { currentBrickTopLeftCorner, currentBrickTopRightCorner, currentBrickBottomLeftCorner, currentBrickBottomRightCorner };
		int collisionCornerIndex = -1;

		for (int i = 0; i < 4; i++) {
			float cornerToCenterXDistance = currentBrickCorners[i].x - ball.GetCenter().x;
			float cornerToCenterYDistance = currentBrickCorners[i].y - ball.GetCenter().y;

			collisionCornerIndex = (cornerToCenterXDistance * cornerToCenterXDistance + cornerToCenterYDistance * cornerToCenterYDistance) < Ball::radius * Ball::radius ? i : collisionCornerIndex;
		}

		if (collisionCornerIndex > -1) {
			Vec2D ballSpeedScaled = ball.GetDirection().Normalized() * 10.0f;
			Vec2D radarVector = ballSpeedScaled + currentBrickCorners[collisionCornerIndex];

			const float m = (radarVector.y - currentBrickCorners[collisionCornerIndex].y) / (radarVector.x - currentBrickCorners[collisionCornerIndex].x);
			const float d = radarVector.y - radarVector.x * m;

			const float h = ball.GetCenter().x;
			const float k = ball.GetCenter().y;

			const float a = (m * m) + 1;
			const float b = 2 * ((m * d) - (m * k) - h);
			const float c = ((h * h) + ((d - k) * (d - k))) - Ball::radius * Ball::radius;

			const float det = (b * b) - (4 * a * c); // will never be negative, since code will execute only if brick corner is inside the ball

			const float r1 = (-b + std::sqrt(det)) / (2 * a);
			const float r2 = (-b - std::sqrt(det)) / (2 * a);

			const float targetRootX = (ball.GetDirection().x < 0) ? std::min(r1, r2) : std::max(r1, r2);
			const float targetRootY = m * targetRootX + d;

			const Vec2D reversalVector = Vec2D{ targetRootX, targetRootY } - currentBrickCorners[collisionCornerIndex];

			ball.Shift(reversalVector);

			const bool outsideLeft = ball.GetCenter().x < currentBrickTopLeftCorner.x && (ball.GetCenter().y < currentBrickTopLeftCorner.y || ball.GetCenter().y > currentBrickBottomLeftCorner.y);
			const bool outsideRight = ball.GetCenter().x > currentBrickTopRightCorner.x && (ball.GetCenter().y < currentBrickTopLeftCorner.y || ball.GetCenter().y > currentBrickBottomLeftCorner.y);
			const bool isOutside = outsideLeft || outsideRight;
			if (!isOutside) {
				const float ballToBrickCenterDistanceX = ball.GetCenter().x - bricks[i].GetRectangle().GetCenter().x;
				const float ballToBrickCenterDistanceY = ball.GetCenter().y - bricks[i].GetRectangle().GetCenter().y;
				const float colissionCornerToBrickCenterDistanceX = currentBrickCorners[collisionCornerIndex].x - bricks[i].GetRectangle().GetCenter().x;
				const float colissionCornerToBrickCenterDistanceY = currentBrickCorners[collisionCornerIndex].y - bricks[i].GetRectangle().GetCenter().y;

				CheckBricksLateralCollision(currentBrickTopLeftCorner, currentBrickBottomRightCorner, currentBrickBottomLeftCorner);
			}
			else {
				switch (collisionCornerIndex) {
				case 0:
					ball.SetDirection({ -1,-1 });
					break;
				case 1:
					ball.SetDirection({ 1,-1 });
					break;
				case 2:
					ball.SetDirection({ -1,1 });
					break;
				case 3:
					ball.SetDirection({ 1,1 });
					break;
				}
			}
		}
		else {
			CheckBricksLateralCollision(currentBrickTopLeftCorner, currentBrickBottomRightCorner, currentBrickBottomLeftCorner);
		}
	}
}

void GameManager::CheckBricksLateralCollision(const Vec2D& currentBrickTopLeftCorner, const Vec2D& currentBrickBottomRightCorner, const Vec2D& currentBrickBottomLeftCorner)
{
	const float ballRightPointX = ball.GetCenter().x + Ball::radius;
	const float ballLeftPointX = ball.GetCenter().x - Ball::radius;
	const float ballTopPointY = ball.GetCenter().y - Ball::radius;
	const float ballBottomPointY = ball.GetCenter().y + Ball::radius;
	const float brickLeft = currentBrickTopLeftCorner.x;
	const float brickRight = currentBrickBottomRightCorner.x;
	const float brickTop = currentBrickTopLeftCorner.y;
	const float brickBottom = currentBrickBottomLeftCorner.y;


	if (ball.GetCenter().y < brickBottom && ball.GetCenter().y > brickTop) {
		if (ballLeftPointX < brickRight && ballLeftPointX > brickLeft && ball.GetDirection().x < 0) {
			ball.Shift({ 0.0f, brickRight - ballLeftPointX });
			ball.InvertXMovement();
		}
		if (ballRightPointX > brickLeft && ballRightPointX < brickRight && ball.GetDirection().x > 0) {
			ball.Shift({ 0.0f, brickLeft - ballRightPointX });
			ball.InvertXMovement();
		}
	}

	if (ball.GetCenter().x < brickRight && ball.GetCenter().x > brickLeft) {
		if (ballBottomPointY < brickBottom && ballBottomPointY > brickTop && ball.GetDirection().y > 0) {
			ball.Shift({ 0.0f, brickTop - ballBottomPointY });
			ball.InvertYMovement();
		}
		if (ballTopPointY < brickBottom && ballTopPointY > brickTop && ball.GetDirection().y < 0) {
			ball.Shift({ 0.0f, ballTopPointY - brickBottom });
			ball.InvertYMovement();
		}
	}
}
