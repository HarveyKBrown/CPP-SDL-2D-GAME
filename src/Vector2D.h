#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
	public:
		float x, y;

		Vector2D();
		Vector2D(float x, float y);

		Vector2D& add(const Vector2D& v);
		Vector2D& subtract(const Vector2D& v);
		Vector2D& multiply(const float& s);
		Vector2D& divide(const float& s);
		Vector2D& normalize();
		float length();

		friend Vector2D& operator+(Vector2D v1, const Vector2D v2);
		friend Vector2D& operator-(Vector2D v1, const Vector2D v2);
		friend Vector2D& operator*(Vector2D v1, const float s);
		friend Vector2D& operator/(Vector2D v1, const float s);

		Vector2D& operator+=(const Vector2D v);
		Vector2D& operator-=(const Vector2D v);
		Vector2D& operator/=(const float s);
		Vector2D& operator*=(const float s);
		bool operator!=(const Vector2D v);
		bool operator==(const Vector2D v);

		Vector2D& zero();
};

#endif
