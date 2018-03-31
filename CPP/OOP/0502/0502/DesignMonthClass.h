// Name: ±i®Ñ»Ê B10615025
// Date: Mar. 31, 2018
// Last Update: Mar. 31, 2018
// Problem statement: Design Month Class
#ifndef DESIGNMONTHCLASS_H
#define DESIGNMONTHCLASS_H

#include <iostream>
#include <string>

using namespace std;

class Month
{
public:
	// Constructor
	Month();
	Month(int);
	Month(char, char, char);

	// Mutator
	void inputInt();
	void inputStr();
	Month nextMonth();

	void setMonthByInt(int);
	void setMonthByStr(char, char, char);

	// Accessor
	void outputInt();
	void outputStr();

private:
	string monthStr;
	unsigned int monthInt;
};

#endif
