// Name: ±i®Ñ»Ê B10615025
// Date: 2018/06/19
// Last Update: 2018/06/19
// Problem statement: Set Exercise
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main()
{
	fstream file("name.txt");
	string line;
	set<string> names;

	while (getline(file, line))
	{
		names.insert(line);
	}

	for (string name : names)
	{
		cout << name << endl;
	}

	return 0;
}