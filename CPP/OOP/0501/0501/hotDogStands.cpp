// Name: ±i®Ñ»Ê B10615025
// Date: Mar. 31, 2018
// Last Update: Mar. 31, 2018
// Problem statement: Hot dog stand

#include "hotDogStands.h"

unsigned int HotDogStand::allSoldHotdogAmount = 0;

HotDogStand::HotDogStand()
{
}

HotDogStand::HotDogStand(string name)
{
	standName = name;
	SoldHotdogAmount = 0;
}

HotDogStand::HotDogStand(string name, unsigned int number)
{
	standName = name;
	SoldHotdogAmount = number;
	allSoldHotdogAmount += number;
}

void HotDogStand::justSold()
{
	// Just sold one hotdog
	SoldHotdogAmount += 1;
	allSoldHotdogAmount += 1;
}

string HotDogStand::allStandsoldAmount()
{
	return to_string(allSoldHotdogAmount);
}

void HotDogStand::print()
{
	cout << standName << " " << SoldHotdogAmount << endl;
}

