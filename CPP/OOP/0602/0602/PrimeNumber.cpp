//Name: 張書銘 B10615025
//Date: Apr. 6, 2018
//Last Update: Apr. 6, 2018
//Problem statement: 質數加減

#include <cmath>
#include "PrimeNumber.h"

PrimeNumber::PrimeNumber() : prime(1)
{
}

PrimeNumber::PrimeNumber(int prime)
{
	if (prime == 1)
	{
		this->prime = 1;
		return;
	}

	this->prime = findGreaterEqualPrime(prime);
}

PrimeNumber PrimeNumber::operator++()
{
	prime = findGreaterEqualPrime(prime + 1);
	PrimeNumber p = *this;
	return PrimeNumber(p);
}

PrimeNumber PrimeNumber::operator--()
{
	prime = findSmallerEqualPrime(prime - 1);
	PrimeNumber p = *this;
	return PrimeNumber(p);
}

PrimeNumber PrimeNumber::operator++(int)
{
	PrimeNumber p = *this;
	prime = findGreaterEqualPrime(prime + 1);
	return PrimeNumber(p);
}

PrimeNumber PrimeNumber::operator--(int)
{
	PrimeNumber p = *this;
	prime = findSmallerEqualPrime(prime - 1);
	return PrimeNumber(p);
}

int PrimeNumber::findGreaterEqualPrime(int prime)
{
	bool flag;
	do
	{
		flag = false;
		for (int i = 2; i <= sqrt(prime); ++i)
		{
			if (prime % i == 0)
			{
				flag = true;
				break;
			}
		}
	} while (flag && ++prime);
	return prime;
}

int PrimeNumber::findSmallerEqualPrime(int prime)
{
	bool flag;
	do
	{
		// prime must >= 1
		if (prime <= 1)
		{
			prime = 1;
			break;
		}

		flag = false;
		for (int i = 2; i <= sqrt(prime); ++i)
		{
			if (prime % i == 0)
			{
				flag = true;
				break;
			}
		}
	} while (flag && --prime);
	return prime;
}
