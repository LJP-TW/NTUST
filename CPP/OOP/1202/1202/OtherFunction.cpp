#include <iostream>
#include <time.h>
#include "OtherFunction.h"

//#define DEBUG_MSG

using namespace std;

// Range of number
extern int rangeMax = 0;
extern int rangeMin = 0;

bool checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess)
	{
		rangeMax = guess - 1;
		cout << "Your guess is too high." << endl;
	}
	else
	{
		rangeMin = guess + 1;
		cout << "Your guess is too low." << endl;
	}
	return false;
}

void play(Player & player1, Player & player2)
{
	srand(time(NULL));
	int answer = 0, guess = 0;
	answer = rand() % 101;
	bool win = false;

	rangeMax = 100;
	rangeMin = 0;

#ifdef DEBUG_MSG
	cout << answer << endl;
#endif

	while (!win)
	{
		cout << "Player 1's turn to guess." << endl;
#ifdef DEBUG_MSG
		cout << "(" << rangeMin << "~" << rangeMax << ")" << endl;
#endif
		guess = player1.getGuess();
		win = checkForWin(guess, answer);

		if (win) return;
		cout << "Player 2's turn to guess." << endl;
#ifdef DEBUG_MSG
		cout << "(" << rangeMin << "~" << rangeMax << ")" << endl;
#endif
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}
