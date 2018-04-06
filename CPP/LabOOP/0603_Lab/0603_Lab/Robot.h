// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 6, 2018
// Last Update: Apr. 6, 2018
// Problem statement: Design a simple robot class
#ifndef ROBOT_H
#define ROBOT_H

#include <string>

using namespace std;

class Robot
{
public:
	// Constructor
	// (0, 0) Power : 100
	Robot();
	// (x, 0) Power : 100
	Robot(double x);
	// (x, y) Power : 100
	Robot(double x, double y);
	// (x, y) Power : power > 0 ? power : 0 // power will be >= 0
	Robot(double x, double y, double power);

	// Accessor
	double getX() { return x; };
	double getY() { return y; };
	double getPower() { return power; };

	// Mutator
	void move(double x, double y);
	string speak(string content);
	void charge(double p) { power += p; };

private:
	// Position
	double x;
	double y;
	double power;
};

#endif