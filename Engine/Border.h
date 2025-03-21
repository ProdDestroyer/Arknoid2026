#pragma once
#include "MyRectangle.h"
#include "Graphics.h"
#include "Colors.h"
class Border
{
public:
	Border(MyRectangle& rectangle, const float offset);
	void draw(Graphics& gfx) const;
	const MyRectangle boundariesRectangle() const;
private:
	float offset;
	MyRectangle rectangle;
	Color colors[6] = {
		 {0, 27, 134},   // Inner left
		{9, 58, 236},   // Outer left
		{1, 46, 201},   // Outer top
		{0, 37, 169},   // Inner top
		{1, 33, 146},   // Inner bottom
		{0, 26, 122}    // Outer bottom
	};
};

