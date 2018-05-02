// Name: ±i®Ñ»Ê
// Date: Apr. 26, 2018
// Last Update: Apr. 26, 2018
// Problem statement: Hungry Caterpillar
#include <iostream>
#include <string>
#include "Caterpillar.h"

using namespace std;

int main()
{
	Caterpillar caterpillar;
	string cmd;

	while (cin >> cmd)
	{
		if (cmd == "EAT")
		{
			string food;
			cin >> food;
			caterpillar.eat(food);
		}
		else if (cmd == "PULL")
		{
			int n;
			cin >> n;
			caterpillar.pull(n);
		}
		else if (cmd == "THROW")
		{
			int n;
			cin >> n;
			caterpillar.throwOut(n);
		}
		else if (cmd == "CONSUME")
		{
			char c;
			cin >> c;
			caterpillar.consume(c);
		}
		else if (cmd == "SORT")
		{
			caterpillar.sort();
		}

		cout << caterpillar << endl;
	}

	return 0;
}