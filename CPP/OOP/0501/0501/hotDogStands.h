// Name: ±i®Ñ»Ê B10615025
// Date: Mar. 31, 2018
// Last Update: Mar. 31, 2018
// Problem statement: Hot dog stand

#ifndef HOTDOGSTANDS_H
#define HOTDOGSTANDS_H

#include <iostream>
#include <string>

using namespace std;

class HotDogStand
{
public:
	// Constructor
	HotDogStand();
	HotDogStand(string);
	HotDogStand(string, unsigned int);

	// Mutator
	void justSold();

	// Accessor
	static string allStandsoldAmount();
	void print();	

private:
	static unsigned int allSoldHotdogAmount;
	string standName;
	unsigned int SoldHotdogAmount;
};



#endif