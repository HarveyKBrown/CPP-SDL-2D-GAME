#include "Vector2D.h"

Vector2D::scale(float a)
{
	x *= a;
	y *= a;
}

Vector2D::add(Vector2D a)
{
	x += a.x;
	y += a.y;
}

Vector2D::subtract(Vector2D a)
{
	x -= a.x;
	y -= a.y;
}
