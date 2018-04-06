// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 5, 2018
// Last Update: Apr. 5, 2018
// Problem statement: ComplexClass
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
public:
	// Constructor
	// 0 + 0i
	Complex();
	// realPart + 0i
	Complex(double);
	// realPart + imaginaryPart
	Complex(double, double);

	// Accessor
	double real();
	double imag();
	double norm();

	// Friend Function
	friend double real(Complex& complex1);
	friend double imag(Complex& complex1);
	friend double norm(Complex& complex1);

	// Operator Overloading
	friend ostream& operator << (ostream&, const Complex&);
	friend istream& operator >> (istream&, Complex&);
	friend Complex operator + (const Complex&, const Complex&);
	friend Complex operator - (const Complex&, const Complex&);
	friend Complex operator * (const Complex&, const Complex&);
	friend Complex operator / (const Complex&, const Complex&);
	friend bool operator == (const Complex&, const Complex&);
	
private:
	// real_ + imaginary_ * i
	double real_;
	double imaginary_;
};

#endif
