// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 21, 2018
// Last Update: Apr. 21, 2018
// Problem statement: Design Polynomial Class
#ifndef DESIGNPOLYNOMIALCLASS_H
#define DESIGNPOLYNOMIALCLASS_H

#include <iostream>

using namespace std;

class Polynomial
{
public:
	// Constructor / Destructor
	Polynomial();
	Polynomial(double);
	Polynomial(double[], size_t);
	Polynomial(const Polynomial&);
	~Polynomial();

	// Operator Overloading
	Polynomial& operator=(const Polynomial&);
	double& operator[](size_t);
	const double& operator[](size_t) const;
	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator-(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, const Polynomial&);

	// Accessors
	friend double evaluate(Polynomial&, double);
	size_t mySize();
	
private:
	// Mutator
	void resize(size_t);

	double *coefficent;
	size_t size;
};

#endif