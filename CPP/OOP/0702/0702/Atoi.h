// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 14, 2018
// Last Update: Apr. 14, 2018
// Problem statement: Array to integer
#ifndef ATOI_H
#define ATOI_H

#include <iostream>
#include <string>

using namespace std;

class Atoi
{
public:
	// Constructor
	Atoi();
	Atoi(string);

	// Accessor
	int Length();
	int StringToInteger();

	// Mutator
	void SetString(string);

	// Helper
	bool IsDigital();

private:
	string beTrans;
	char sign;
};

#endif