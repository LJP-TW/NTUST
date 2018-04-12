// Name: ±i®Ñ»Ê
// Date: Apr. 12, 2018
// Last Update: Apr. 12, 2018
// Problem statement: Rect
#include <iostream>
#include "Rect.h"

Rect::Rect() : x(0), y(0), width(0), height(0)
{
}

Rect::Rect(int x, int y, int width, int height) : x(x), y(y), width(width), height(height)
{
}

Rect Rect::operator+(Rect & rect1)
{
	int maxX;
	int maxY;
	int minX;
	int minY;

	// left-top point is (minX, maxY)
	minX = x < rect1.x ? x : rect1.x;
	maxY = y > rect1.y ? y : rect1.y;

	maxX = x + width > rect1.x + rect1.width ? x + width : rect1.x + rect1.width;
	minY = y - height < rect1.y - rect1.height ? y - height : rect1.y - rect1.height;

	return Rect(minX, maxY, maxX - minX, maxY - minY);
}

Rect Rect::operator*(Rect & rect1)
{
	int pX;
	int pY;
	int pWidth;
	int pHeight;
	int minX;
	int minY;

	// X-axis check
	Rect lRect;
	Rect rRect;

	if (x < rect1.x)
	{
		lRect = *this;
		rRect = rect1;
	}
	else
	{
		lRect = rect1;
		rRect = *this;
	}

	if (lRect.x + lRect.width < rRect.x)
	{
		std::cout << "Not overlapping" << std::endl;
		return Rect();
	}

	// Y-axis check
	Rect tRect;
	Rect bRect;
	if (y > rect1.y)
	{
		tRect = *this;
		bRect = rect1;
	}
	else
	{
		tRect = rect1;
		bRect = *this;
	}

	if (tRect.y - tRect.height > bRect.y)
	{
		std::cout << "Not overlapping" << std::endl;
		return Rect();
	}

	// Setting parameters
	pX = rRect.x;
	pY = bRect.y;
	
	minX = lRect.x + lRect.width < rRect.x + rRect.width ? lRect.x + lRect.width : rRect.x + rRect.width;
	pWidth = minX - pX;

	minY = tRect.y - tRect.height > bRect.y - bRect.height ? tRect.y - tRect.height : bRect.y - bRect.height;
	pHeight = pY - minY;

	return Rect(pX, pY, pWidth, pHeight);
}

std::string Rect::toString()
{
	std::string str = "( " + std::to_string(x) + " , " + std::to_string(y) + " , " + std::to_string(width) + " , " + std::to_string(height) + " )";
	return str;
}
