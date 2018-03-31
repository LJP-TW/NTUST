// Name: B10615025 張書銘
// Date: Mar. 22, 2018
// Last Update: Mar. 22, 2018
// Problem statement: Fraction

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction
{
public:
	void setNumerator(int);
	void setDenominator(int);

	double getDouble();
	void outputReducedFraction();
private:
	int numerator;
	int denominator;

	// Get GCD of two number
	int gcd(int, int);
};

#endif