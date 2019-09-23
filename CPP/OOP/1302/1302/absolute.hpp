// Name: 張書銘 B10615025
// Date: 2018/6/4 下午 02:00:44
// Last Update: 2018/6/4 下午 02:00:44
// Problem statement: AbsoluteValue
#ifndef ABSOLUTEVALUE_H
#define ABSOLUTEVALUE_H

#include <iostream>
#include <cmath>

using namespace std;

template<class T>
auto absoluteValue(T v1, T v2)
{
	return abs(v1 - v2);
}

#endif