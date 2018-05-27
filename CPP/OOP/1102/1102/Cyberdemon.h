// Name: 張書銘 B10615025
// Date: 2018/5/19 上午 11:56:09
// Last Update: 2018/5/19 上午 11:56:09
// Problem statement: Creatures
#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "Creatures.h"

class Cyberdemon : public Demon
{
public:
	// Constructor
	Cyberdemon();
	Cyberdemon(int newStrength, int newHit);

	// Returns amount of damage this creature
	// inflicts in one round of combat
	virtual int getDamage();

	virtual string getSpecies();

private:
};

#endif