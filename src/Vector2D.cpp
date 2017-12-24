#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D() {
	x = 0.0f;
	y = 0.0f;
}

void Vector2D::multiply(float a) {
	x *= a;
	y *= a;
}

void Vector2D::add(Vector2D a) {
	x += a.x;
	y += a.y;
}

void Vector2D::divide(float a) {
	x /= a;
	y /= a;
}

void Vector2D::subtract(Vector2D a) {
	x -= a.x;
	y -= a.y;
}

void Vector2D::operator+(Vector2D a, Vector2D b) {
	return this->add(a);
}
void Vector2D::operator-(Vector2D a) {
	return this->subtract(a);
}
void Vector2D::operator/(float a) {
	return this->divide(a);
}
void Vector2D::operator*(float a) {
	return this->multiply(a);
}

void Vector2D::operator+=(Vector2D a) {
	this->add(a);
}
void Vector2D::operator-=(Vector2D a) {
	this->subtract(a);
}
void Vector2D::operator/=(float a) {
	this->divide(a);
}
void Vector2D::operator*=(float a) {
	this->multiply(a);
}
