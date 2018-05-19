// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#ifndef DEMON_H
#define DEMON_H

#include "Creatures.h"

class Demon : public Creature
{
public:
	// Constructor
	Demon();
	Demon(int newStrength, int newHit);

	// Returns amount of damage this creature
	// inflicts in one round of combat
	virtual int getDamage(string species);
};

#include "Cyberdemon.h"
#include "Balrog.h"

#endif
