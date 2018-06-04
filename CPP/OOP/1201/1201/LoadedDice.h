// Name: 張書銘 B10615025
// Date: 2018/5/27 下午 08:22:08
// Last Update: 2018/5/27 下午 08:22:08
// Problem statement: Dice
#ifndef LOADEDDICE_H
#define LOADEDDICE_H

#include <iostream>
#include "Dice.h"

using namespace std;

class LoadedDice : public Dice
{
public:
	// Constructor
	LoadedDice();
	LoadedDice(int);

	// Other functions
	virtual int rollDice() const;
};

#endif