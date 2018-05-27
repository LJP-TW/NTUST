// Name: ±i®Ñ»Ê B10615025
// Date: May. 19, 2018
// Last Update: May. 19, 2018
// Problem statement: WordGame
#include <iostream>
#include <fstream>
#include <string>
#define N 4
#define FILE_NAME "words.txt"

using namespace std;

struct grid
{
	char alpha;
	bool used;
};

grid gameBoard[N][N];

void readGameBoard();

bool isValid(string);

bool isValidRecursive(string, int, int);

int main()
{
	fstream wordsFile(FILE_NAME);
	string words;

	// Init
	readGameBoard();

	// Main Loop
	while (wordsFile >> words)
	{
		if (isValid(words))
		{
			cout << words << endl;
		}
	}
	system("pause");
	return 0;
}

void readGameBoard()
{
	char c;

	for (int h = 0; h < N; ++h)
	{
		for (int w = 0; w < N; ++w)
		{
			cin >> c;
			grid g;
			g.alpha = c;
			g.used = false;
			gameBoard[h][w] = g;
		}
	}
}

bool isValid(string words)
{
	// Find initial point
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (gameBoard[y][x].alpha == words[0])
			{
				string tWords = words;

				// Init GameBoard
				for (int y = 0; y < N; ++y)
				{
					for (int x = 0; x < N; ++x)
					{
						gameBoard[y][x].used = false;
					}
				}

				gameBoard[y][x].used = true;
				tWords.erase(tWords.begin());

				// Recursive
				if (isValidRecursive(tWords, x, y))
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool isValidRecursive(string words, int x, int y)
{
	// If every char in words is matched
	if (words == "")
	{
		return true;
	}

	// Search around
	for (int i = 0; i < 9; ++i)
	{
		int tX = (x - 1) + i % 3;
		int tY = (y - 1) + i / 3;

		if (0 <= tX && tX < N && 0 <= tY && tY < N && gameBoard[tY][tX].used == false && gameBoard[tY][tX].alpha == words[0])
		{
			string tWords = words;

			gameBoard[tY][tX].used = true;
			tWords.erase(tWords.begin());
			if (isValidRecursive(tWords, tX, tY))
			{
				return true;
			}
			gameBoard[tY][tX].used = false;
		}
	}

	return false;
}