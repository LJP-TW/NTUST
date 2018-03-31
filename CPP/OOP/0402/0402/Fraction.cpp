// Name: B10615025 張書銘
// Date: Mar. 22, 2018
// Last Update: Mar. 22, 2018
// Problem statement: Fraction

#include "Fraction.h"

void Fraction::setNumerator(int n)
{
	numerator = n;
}

void Fraction::setDenominator(int d)
{
	denominator = d;
}

double Fraction::getDouble()
{
	return (double)numerator / denominator;
}

void Fraction::outputReducedFraction()
{
	int d = gcd(numerator, denominator);

	if (denominator == d)
	{
		cout << numerator / d;
	}
	else
	{
		cout << numerator / d << "/" << denominator / d;
	}
}

int Fraction::gcd(int a, int b)
{
	// Euclidean algorithm
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;		
	}

	return a;
}