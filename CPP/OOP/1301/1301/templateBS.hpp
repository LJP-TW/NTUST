// Name: 張書銘 B10615025
// Date: 2018/6/4 下午 12:55:46
// Last Update: 2018/6/4 下午 12:55:46
// Problem statement: templateBS
#ifndef TEMPLATEBS_H
#define TEMPLATEBS_H

#include <iostream>

using namespace std;

template<class T>
void ItrSearch(T _array[], int startIndex, int finalIndex, T key, bool& result, int& location)
{
	result = false;

	while (finalIndex >= startIndex)
	{
		location = startIndex + (finalIndex - startIndex) / 2;

		if (key == _array[location])
		{
			result = true;
			break;
		}

		if (key > _array[location])
		{
			startIndex = location + 1;
		}
		else
		{
			finalIndex = location - 1;
		}
	}
}

template<class T>
void recBinSrch(T _array[], int startIndex, int finalIndex, T key, bool& result, int& location)
{
	result = false;

	if (finalIndex >= startIndex)
	{
		location = startIndex + (finalIndex - startIndex) / 2;

		if (key == _array[location])
		{
			result = true;
			return;
		}

		if (key > _array[location])
		{
			return recBinSrch(_array, location + 1, finalIndex, key, result, location);
		}
		else
		{
			return recBinSrch(_array, startIndex, location - 1, key, result, location);
		}
	}

	return;
}

#endif