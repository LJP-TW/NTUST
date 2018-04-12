// Name: ±i®Ñ»Ê
// Date: Apr. 12, 2018
// Last Update: Apr. 12, 2018
// Problem statement: Rect
#ifndef RECT_H
#define RECT_H

#include <string>

class Rect
{
public:
	// Constructor
	Rect();
	Rect(int, int, int, int);

	// Operator Overloading
	// A + B
	// Return Rect that is the smallest Rect which can contain A and B
	Rect operator + (Rect&);
	// A * B
	// Return Rect that is the overlapping of A and B
	Rect operator * (Rect&);

	// Accessor
	std::string toString();
private:
	int x;
	int y;
	int width;
	int height;
};

#endif