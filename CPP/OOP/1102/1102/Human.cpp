// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#include "Human.h"

Human::Human() : Creature()
{
}

Human::Human(int newStrength, int newHit) : Creature(newStrength, newHit)
{
}

int Human::getDamage()
{
	int damage = Creature::getDamage();

	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;

	return damage;
}

string Human::getSpecies()
{
	return string("Human");
}
