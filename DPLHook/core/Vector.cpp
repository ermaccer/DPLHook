#include "Vector.h"

inline float RecipSqrt(float x, float y) { return x / sqrt(y); }
inline float RecipSqrt(float x) { return RecipSqrt(1.0f, x); }

void Vector::Normalise()
{
	float sq = MagnitudeSqr();
	if (sq > 0.0f) {
		float invsqrt = RecipSqrt(sq);
		X *= invsqrt;
		Y *= invsqrt;
		Z *= invsqrt;
	}
	else
		X = 1.0f;
}

Vector CrossProduct(const Vector& v1, const Vector& v2)
{
	return Vector(v1.Y * v2.Z - v1.Z * v2.Y, v1.Z * v2.X - v1.X * v2.Z, v1.X * v2.Y - v1.Y * v2.X);
}