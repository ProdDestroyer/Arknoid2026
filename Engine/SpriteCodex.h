#pragma once

#include "Graphics.h"
#include "Vec2D.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall(const Vec2D& center, Graphics& gfx);
	// centered drawing of 200x160 sprite
	static void DrawTitle(const Vec2D& center, Graphics& gfx);
	// centered drawing of 84x64 sprite
	static void SpriteCodex::DrawGameOver(const Vec2D& center, Graphics& gfx);
	// centered drawing of 104x19 sprite
	static void SpriteCodex::DrawReady(const Vec2D& center, Graphics& gfx);
	// centered drawing of 24x24 sprite
	static void SpriteCodex::DrawPoo(const Vec2D& center, Graphics& gfx);
};