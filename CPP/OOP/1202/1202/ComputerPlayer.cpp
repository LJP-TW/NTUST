#include <cstdlib>
#include <iostream>
#include "ComputerPlayer.h"

extern int rangeMax;
extern int rangeMin;

using namespace std;

ComputerPlayer::ComputerPlayer()
{
}

int ComputerPlayer::getGuess()
{
	// Return a random number in the range
	int guess = rand() % (rangeMax - rangeMin + 1) + rangeMin;
	cout << guess << endl;
	return guess;
}
