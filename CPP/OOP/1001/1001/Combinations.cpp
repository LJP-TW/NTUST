// Name: ±i®Ñ»Ê B10615025
// Date: May. 15, 2018
// Last Update: May. 15, 2018
// Problem statement: Combinations
#include "Combinations.h"

int globalIntSize = 0;
int *globalInt = NULL;

void PrintCombination(int *list, int n, int r)
{
	if (r == 0)
	{
		cout << globalInt[0];
		for (int i = 1; i < globalIntSize; ++i)
		{
			cout << ' ' << globalInt[i];
		}
		cout << endl;
		return;
	}

	// Record recent position of globalInt
	int nowPos = globalIntSize;
	
	// Resize globalStr and Copy old globalStr
	++globalIntSize;
	int *temp = globalInt;
	globalInt = new int[globalIntSize];
	for (int i = 0; i < nowPos; ++i)
	{
		globalInt[i] = temp[i];
	}
	if (temp != NULL)
	{
		delete[] temp;
	}
	
	// Fill number into globalInt
	for (int i = 0; n - i >= r; ++i)
	{
		globalIntSize = nowPos + 1;
		globalInt[nowPos] = list[i];
		PrintCombination(&list[i + 1], n - i - 1, r - 1);
	}
}