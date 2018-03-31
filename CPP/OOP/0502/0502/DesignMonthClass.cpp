// Name: ±i®Ñ»Ê B10615025
// Date: Mar. 31, 2018
// Last Update: Mar. 31, 2018
// Problem statement: Design Month Class
#include "DesignMonthClass.h"

string monthAbbreviation[] = 
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

Month::Month()
{
	// Default is January
	monthStr = monthAbbreviation[0];
	monthInt = 1;
}

Month::Month(int month)
{
	setMonthByInt(month);
}

Month::Month(char monthChar1, char monthChar2, char monthChar3)
{
	setMonthByStr(monthChar1, monthChar2, monthChar3);
}

void Month::inputInt()
{
	int temp;
	cin >> temp;
	setMonthByInt(temp);
}

void Month::inputStr()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	setMonthByStr(s1[0], s2[0], s3[0]);
}

Month Month::nextMonth()
{
	return Month(monthInt + 1);
}

void Month::setMonthByInt(int month)
{
	if (month < 0 || month > 12)
	{
		// Out of range
		monthStr = monthAbbreviation[0];
		monthInt = 1;
		return;
	}
	monthStr = monthAbbreviation[month - 1];
	monthInt = month;
}

void Month::setMonthByStr(char monthChar1, char monthChar2, char monthChar3)
{
	for (int i = 0; i < 12; ++i)
	{
		if (monthAbbreviation[i][0] == monthChar1 && monthAbbreviation[i][1] == monthChar2 && monthAbbreviation[i][2] == monthChar3)
		{
			monthStr = monthAbbreviation[i];
			monthInt = i + 1;
			return;
		}
	}

	// If no matching string
	monthStr = monthAbbreviation[0];
	monthInt = 1;
}

void Month::outputInt()
{
	cout << monthInt;
}

void Month::outputStr()
{
	cout << monthStr;
}

