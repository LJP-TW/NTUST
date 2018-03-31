// Name: B10615025 張書銘
// Date: Mar. 22, 2018
// Last Update: Mar. 22, 2018
// Problem statement: ClassPointInPlane

#include "ClassPointInPlane.h"

void Point::set(int pX, int pY)
{
	x = pX;
	y = pY;
}

void Point::move(int pX, int pY)
{
	x += pX;
	y += pY;
}

void Point::rotate()
{
	// Multipling the slopes of two perpendicular lines will get -1
	// if clockwise : 
	//		newX = oldY
	//		newY = -oldX
	// else if Counterclockwise:
	//		newX = -oldY
	//		newY = oldX
	//
	// Now, this function is clockwise rotation.
	int oldX = x;
	int oldY = y;
	x = oldY;
	y = -oldX;
}

int Point::retrieveVertical()
{
	return x;
}

int Point::retrieveHorizontal()
{
	return y;
}