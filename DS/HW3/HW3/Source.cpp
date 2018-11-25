#include <iostream>
#include <sstream>
#include <string>
#include "GeneralizedList3.h"

using namespace std;

PolyList3 tree;

void hint()
{
	cout << "Choose Act, please input act ID:" << endl;
	cout << "1: Input" << endl;
	cout << "2: retCoeff()" << endl;
	cout << "3: Mulf()" << endl;
}

void cmd1()
{
	string buf;
	int coef;
	int *e = new int[3];
	cout << "Please input, ending with '.'" << endl;
	while (getline(cin, buf))
	{
		if (buf == ".")
		{
			break;
		}

		istringstream iss(buf);
		iss >> coef >> e[0] >> e[1] >> e[2];

		tree.create(coef, e);
	}

	delete[] e;
}

void cmd2() 
{
	string buf;
	int *e = new int[3];

	cout << "Please input" << endl;
	cin >> e[0] >> e[1] >> e[2];

	try
	{
		cout << "retCoeff(" << e[0] << ',' << e[1] << ',' << e[2] << ") = " << tree.retCoeff(e) << endl;
	}
	catch (PolyListRetCoeffException& error)
	{
		cout << error.errorMsg() << endl;
	}

	delete[] e;
}

void cmd3()
{
	string buf;
	int *e = new int[3];

	cout << "Please input" << endl;
	cin >> e[0] >> e[1] >> e[2];

	tree.mulf(e);

	delete[] e;
}

int main()
{
	int cmd;

	hint();

	while ((cin >> cmd))
	{
		switch (cmd)
		{
		case 1:
			cmd1();
			break;
		case 2:
			cmd2();
			break;
		case 3:
			cmd3();
			break;
		default:
			break;
		}

		hint();
	}

	return 0;
}