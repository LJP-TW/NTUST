// Name: 張書銘 B10615025
// Date: 2018/5/19 上午 11:56:24
// Last Update: 2018/5/19 上午 11:56:24
// Problem statement: Creatures
#ifndef BALROG_H
#define BALROG_H

#include "Creatures.h"

class Balrog : public Demon
{
public:
	// Constructor
	Balrog();
	Balrog(int newStrength, int newHit);

	// Returns amount of damage this creature
	// inflicts in one round of combat
	virtual int getDamage();

private:
};

#endif