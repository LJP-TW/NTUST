//Name: 張書銘 B10615025
//Date: Apr. 6, 2018
//Last Update: Apr. 6, 2018
//Problem statement: 質數加減

#ifndef PRIMENUMBER_H
#define PRIMENUMBER_H

class PrimeNumber
{
public:
	// Constructor
	// Set to 1
	PrimeNumber();
	// Set to first prime >= prime
	PrimeNumber(int prime);

	// Accessor
	int get() { return prime; };

	// Operator Overloading
	// ++p is equivalent to p.++()
	PrimeNumber operator ++();
	PrimeNumber operator --();
	// p++ is equivalent to p.++(0)
	PrimeNumber operator ++(int);
	PrimeNumber operator --(int);

private:
	// find next prime which >= p
	int findGreaterEqualPrime(int p);
	// find next prime which <= p
	int findSmallerEqualPrime(int p);
	int prime;

};

#endif