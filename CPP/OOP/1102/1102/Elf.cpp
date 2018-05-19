// Name: ±i®Ñ»Ê B10615025
// Date: 2018/5/19
// Last Update: 2018/5/19
// Problem statement: Creatures
#include "Elf.h"
#define getSpecies() "Elf"

Elf::Elf() : Creature()
{
}

Elf::Elf(int newStrength, int newHit) : Creature(newStrength, newHit)
{
}

int Elf::getDamage()
{
	int damage = Creature::getDamage();

	cout << getSpecies() << " attacks for " <<
		damage << " points!" << endl;

	// Elves inflict double magical damage with a 10% chance
	if ((rand() % 10) == 0)
	{
		cout << "Magical attack inflicts " << damage <<
			" additional damage points!" << endl;
		damage = damage * 2;
	}

	return damage;
}
