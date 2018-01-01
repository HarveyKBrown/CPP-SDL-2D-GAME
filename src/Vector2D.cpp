#include "Vector2D.h"
#include <cmath>


Vector2D::Vector2D() : x(0), y(0) {}
Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D& Vector2D::add(const Vector2D& v)
{
	this->x += v.x;
	this->y += v.y;

	return *this;
}

Vector2D& Vector2D::subtract(const Vector2D& v)
{
	this->x -= v.x;
	this->y -= v.y;

	return *this;
}

Vector2D& Vector2D::multiply(const float& s)
{
	this->x *= s;
	this->y *= s;

	return *this;
}

Vector2D& Vector2D::divide(const float& s)
{
	this->x /= s;
	this->y /= s;

	return *this;
}

float Vector2D::length()
{
	return std::sqrt(x*x + y*y);
}

Vector2D& Vector2D::normalize()
{
	if (length() == 0)
			return *this;
	*this = *this / length();
	return *this;
}

Vector2D& operator+(Vector2D v1, const Vector2D v2)
{ return v1.add(v2); }
Vector2D& operator-(Vector2D v1, const Vector2D v2)
{ return v1.subtract(v2); }
Vector2D& operator*(Vector2D v1, const float s)
{ return v1.multiply(s); }
Vector2D& operator/(Vector2D v1, const float s)
{ return v1.divide(s); }

Vector2D& Vector2D::operator+=(const Vector2D v)
{ return this->add(v); }
Vector2D& Vector2D::operator-=(const Vector2D v)
{ return this->subtract(v); }
Vector2D& Vector2D::operator/=(const float s)
{ return this->divide(s); }
Vector2D& Vector2D::operator*=(const float s)
{ return this->multiply(s); }

bool Vector2D::operator!=(const Vector2D v)
{
	if (this->x != v.x || this->y != v.y)
		return true;
	return false;
}
bool Vector2D::operator==(const Vector2D v)
{
	if (this->x == v.x && this->y == v.y)
		return true;
	return false;
}

Vector2D& Vector2D::zero()
{
	this->x = 0;
	this->y = 0;

	return *this;
}
