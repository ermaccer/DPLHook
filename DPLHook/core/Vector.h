#pragma once
#include <math.h>

class Vector
{
public:
	float X, Y, Z;
	Vector(void) {}
	Vector(float a, float b, float c)
	{
		X = a;
		Y = b;
		Z = c;
	}
	float Heading(void) const { return atan2(-X, Y); }
	float Magnitude(void) const { return sqrt(X * X + Y * Y + Z * Z); }
	float MagnitudeSqr(void) const { return X * X + Y * Y + Z * Z; }
	float Magnitude2D(void) const { return sqrt(X * X + Y * Y); }
	float MagnitudeSqr2D(void) const { return X * X + Y * Y; }
	void Normalise();

	const Vector& operator+=(Vector const& right) {
		X += right.X;
		Y += right.Y;
		Z += right.Z;
		return *this;
	}

	const Vector& operator+=(float const& right) {
		X += right;
		Y += right;
		Z += right;
		return *this;
	}

	const Vector& operator-=(Vector const& right) {
		X -= right.X;
		Y -= right.Y;
		Z -= right.Z;
		return *this;
	}

	const Vector& operator*=(float right) {
		X *= right;
		Y *= right;
		Z *= right;
		return *this;
	}

	const Vector& operator/=(float right) {
		X /= right;
		Y /= right;
		Z /= right;
		return *this;
	}

	Vector operator-() const {
		return Vector(-X, -Y, -Z);
	}
};

inline Vector operator+(const Vector& left, const Vector& right)
{
	return Vector(left.X + right.X, left.Y + right.Y, left.Z + right.Z);
}

inline Vector operator-(const Vector& left, const Vector& right)
{
	return Vector(left.X - right.X, left.Y - right.Y, left.Z - right.Z);
}

inline Vector operator*(const Vector& left, float right)
{
	return Vector(left.X * right, left.Y * right, left.Z * right);
}

inline Vector operator*(float left, const Vector& right)
{
	return Vector(left * right.X, left * right.Y, left * right.Z);
}

inline Vector operator/(const Vector& left, float right)
{
	return Vector(left.X / right, left.Y / right, left.Z / right);
}

Vector CrossProduct(const Vector& v1, const Vector& v2);