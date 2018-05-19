// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#ifndef CREATURES_H
#define CREATURES_H

#include <iostream>
#include <string>

using namespace std;

class Creature
{
public:
	// Initialize to human, 10 strength, 10 hit points
	Creature();

	// Initialize creature to new type, strength, hit points
	// Also add appropriate accessor and mutator functions
	// for type, strength, and hit points
	Creature(int newStrength, int newHit);

	// Returns amount of damage this creature
	// inflicts in one round of combat
	virtual int getDamage();

protected:
	int strength; // How much damage we can inflict
	int hitpoints; // How much damage we can sustain

};

#include "Demon.h"
#include "Elf.h"
#include "Human.h"

#endif