#include <iostream>
#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer()
{
}

int HumanPlayer::getGuess()
{
	int number;

	cin >> number;

	return number;
}
