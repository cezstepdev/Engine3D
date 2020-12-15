#include "Mouse.h"

Mouse::Mouse()
{
    //ctor
}

Mouse::~Mouse()
{
    //dtor
}

void Mouse::centerCursor(int centerX, int centerY)
{
	if(x != centerX || y != centerY)
    {
		x = centerX;
		y = centerY;
		glutWarpPointer(x, y);
	}
}
