// Name: B10615025 張書銘
// Date: Mar. 22, 2018
// Last Update: Mar. 22, 2018
// Problem statement: ClassPointInPlane

#ifndef CLASS_POINT_IN_PLANE_H
#define CLASS_POINT_IN_PLANE_H

#include <iostream>

using namespace std;

// This is a int Point
// In the future, someone can use template to make it better
class Point
{
public:
	// Call set first
	void set(int pX, int pY);

	// Accumulate
	void move(int pX, int pY);

	// Clockwise rotation
	void rotate();

	int retrieveVertical();
	int retrieveHorizontal();
private:
	// point(x, y)
	int x = 0;
	int y = 0;
};

#endif