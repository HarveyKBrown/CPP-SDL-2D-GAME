class Vector2D
{
	public:
		float x;
		float y;

		Vector2D();
		Vector2D(float x, float y);

		void multiply(float a);
		void divide(float a);
		void add(Vector2D a);
		void subtract(Vector2D a);

		Vector2D& operator+(Vector2D a, Vector2D b);
		Vector2D& operator-(Vector2D a, Vector2D b);
		Vector2D& operator/(Vector2D a, float a);
		Vector2D& operator*(Vector2D a, float a);

		void operator+=(Vector2D a);
		void operator-=(Vector2D a);
		void operator/=(float a);
		void operator*=(float a);

};
