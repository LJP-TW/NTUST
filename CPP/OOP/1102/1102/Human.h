// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#ifndef HUMAN_H
#define HUMAN_H

#include "Creatures.h"

using namespace std;

class Human : public Creature
{
public:
	// Constructor
	Human();
	Human(int newStrength, int newHit);

	// Returns amount of damage this creature
	// inflicts in one round of combat
	virtual int getDamage();
};

#endif