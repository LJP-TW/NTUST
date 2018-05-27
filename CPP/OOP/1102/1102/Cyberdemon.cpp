// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#include "Cyberdemon.h"

Cyberdemon::Cyberdemon() : Demon()
{
}

Cyberdemon::Cyberdemon(int newStrength, int newHit) : Demon(newStrength, newHit)
{
}

int Cyberdemon::getDamage()
{
	int damage = Demon::getDamage(getSpecies());

	return damage;
}

string Cyberdemon::getSpecies()
{
	return string("Cyberdemon");
}

