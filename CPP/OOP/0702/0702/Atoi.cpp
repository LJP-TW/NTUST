// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 14, 2018
// Last Update: Apr. 14, 2018
// Problem statement: Array to integer
#include "Atoi.h"

Atoi::Atoi()
{
}

Atoi::Atoi(string beTrans)
{
	SetString(beTrans);
}

int Atoi::Length()
{
	return (int)beTrans.size();
}

int Atoi::StringToInteger()
{
	int result = 0;
	for (char i : beTrans)
	{
		result *= 10;
		result += (i - '0');
	}
	return sign == '-' ? -result : result;
}

void Atoi::SetString(string beTrans)
{
	if (beTrans[0] == '-')
	{
		sign = '-';
		beTrans.erase(0, 1);
	}
	else if (beTrans[0] == '+')
	{
		sign = '+';
		beTrans.erase(0, 1);
	}
	else
		sign = '+';

	this->beTrans = beTrans;
}

bool Atoi::IsDigital()
{
	for (char i : beTrans)
	{
		if (i < '0' || '9' < i)
		{
			return false;
		}
	}
	return true;	
}
