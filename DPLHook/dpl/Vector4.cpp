#include "Vector4.h"

Vector4::Vector4()
{
	X = Y = Z = W = 0.0f;
}

Vector4::Vector4(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
	W = 1.0f;
}
