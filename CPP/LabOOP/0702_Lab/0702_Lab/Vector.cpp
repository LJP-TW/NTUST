#include "Vector.h"
// Name: ±i®Ñ»Ê
// Date: Apr. 12, 2018
// Last Update: Apr. 12, 2018
// Problem statement: Vector Computation

Vector::Vector()
{
}

Vector::Vector(float x, float y) : x(x), y(y)
{
}

Vector Vector::operator+(Vector & vector1)
{
	return Vector(x + vector1.x, y + vector1.y);
}

Vector Vector::operator-(Vector & vector1)
{
	return Vector(x - vector1.x, y - vector1.y);
}

float Vector::operator*(Vector & vector1)
{
	return x * vector1.x + y * vector1.y;
}

Vector Vector::operator*(float k)
{
	return Vector(x * k, y * k);
}
