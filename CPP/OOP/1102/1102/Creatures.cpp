// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#include "Creatures.h"

Creature::Creature() : strength(10), hitpoints(10)
{
}

Creature::Creature(int newStrength, int newHit) : strength(newStrength), hitpoints(newHit)
{
}

int Creature::getDamage()
{
	int damage;
	// All creatures inflict damage which is a
	// random number up to their strength
	damage = (rand() % strength) + 1;
	
	return damage;
}