// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 6, 2018
// Last Update: Apr. 6, 2018
// Problem statement: Design a simple robot class
#include <cmath>
#include <cctype>
#include "Robot.h"

Robot::Robot() : x(0), y(0), power(100)
{
}

Robot::Robot(double x) : x(x), y(0), power(100)
{
}

Robot::Robot(double x, double y) : x(x), y(y), power(100)
{
}

Robot::Robot(double x, double y, double power) : x(x), y(y), power(power > 0 ? power : 0)
{
}

void Robot::move(double x, double y)
{
	// Distance is equivalent to cost
	double distance = sqrt(x * x + y * y);

	// Unit Vector
	double unitX = x / sqrt(x * x + y * y);
	double unitY = y / sqrt(x * x + y * y);
	
	// If the total cost > current existing power
	// Move until no power
	if (distance > power)
	{
		distance = power;
	}

	// Moving
	this->x += (unitX * distance);
	this->y += (unitY * distance);
	power -= distance;
}

string Robot::speak(string content)
{
	string result = "";

	for (int index = 0; content[index]; ++index)
	{
		if (islower(content[index]))
		{
			// If power is not enough
			if (power < 1)
			{
				break;
			}
			result += toupper(content[index]);
			power -= 1;
		}
		else if (isupper(content[index]))
		{
			// If power is not enough
			if (power < 2)
			{
				break;
			}
			result += tolower(content[index]);
			power -= 2;
		}
		else
		{
			// If power is not enough
			if (power < 0.5)
			{
				break;
			}
			result += content[index];
			power -= 0.5;
		}
	}

	return result;
}
