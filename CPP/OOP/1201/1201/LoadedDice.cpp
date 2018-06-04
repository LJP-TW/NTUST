#include <cstdlib>
#include <time.h>
#include "LoadedDice.h"

LoadedDice::LoadedDice() : Dice()
{
}

LoadedDice::LoadedDice(int numSides) : Dice(numSides)
{
}

int LoadedDice::rollDice() const
{
	// return the largest number possible with 50% chance
	if (rand() % 2)
	{
		return numSides;
	}

	// return what Dice's rollDice function returns with 50% chance
	else
	{
		return Dice::rollDice();
	}
}
