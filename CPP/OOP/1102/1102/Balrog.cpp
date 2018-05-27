// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#include "Balrog.h"

Balrog::Balrog() : Demon()
{
}

Balrog::Balrog(int newStrength, int newHit) : Demon(newStrength, newHit)
{
}

int Balrog::getDamage()
{
	int damage = Demon::getDamage(getSpecies());

	int damage2 = (rand() % getStrength()) + 1;
	cout << "Balrog speed attack inflicts " << damage2 <<
		" additional damage points!" << endl;
	damage = damage + damage2;

	return damage;
}

string Balrog::getSpecies()
{
	return string("Balrog");
}

