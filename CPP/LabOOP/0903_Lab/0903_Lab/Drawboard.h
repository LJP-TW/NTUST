// Name: ±i®Ñ»Ê
// Date: Apr. 26, 2018
// Last Update: Apr. 26, 2018
// Problem statement: Draw Board
#ifndef DRAWBOARD_H
#define DRAWBOARD_H

#include <iostream>

class Drawboard
{
public:
	// Constructor
	Drawboard();
	Drawboard(int, int);

	void rect(int, int, int, int, char);
	void circle(int, int, int, char);

	friend std::ostream& operator<<(std::ostream&, const Drawboard&);

private:
	char **board;
	int width, height;
};

#endif