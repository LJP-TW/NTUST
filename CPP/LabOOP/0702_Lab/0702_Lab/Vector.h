// Name: ±i®Ñ»Ê
// Date: Apr. 12, 2018
// Last Update: Apr. 12, 2018
// Problem statement: Vector Computation
#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
	// Constructor
	Vector();
	Vector(float, float);

	// Operator Overloading
	Vector operator +(Vector&);
	Vector operator -(Vector&);
	float operator *(Vector&);
	Vector operator *(float);

	// Data member
	// Vector(x, y)
	float x, y;
};

#endif