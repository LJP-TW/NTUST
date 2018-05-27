// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#include "Demon.h"

Demon::Demon() : Creature()
{
}

Demon::Demon(int newStrength, int newHit) : Creature(newStrength, newHit)
{
}

int Demon::getDamage(string species)
{
	int damage = Creature::getDamage();

	cout << species << " attacks for " <<
		damage << " points!" << endl;

	// Demons can inflict damage of 50 with a 5% chance
	if ((rand() % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 "
			<< " additional damage points!" << endl;
	}

	return damage;
}

string Demon::getSpecies()
{
	return string("Unknown");
}
