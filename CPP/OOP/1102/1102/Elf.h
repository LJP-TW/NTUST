// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#ifndef ELF_H
#define ELF_H

#include "Creatures.h"

class Elf : public Creature
{
public:
	// Constructor
	Elf();
	Elf(int newStrength, int  newHit);

	// Returns amount of damage this creature
	// inflicts in one round of combat
	virtual int getDamage();
};

#endif