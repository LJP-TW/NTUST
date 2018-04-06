// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 5, 2018
// Last Update: Apr. 5, 2018
// Problem statement: ComplexClass
#include "complex.h"

Complex::Complex()
{
	real_ = 0;
	imaginary_ = 0;
}

Complex::Complex(double real)
{
	real_ = real;
	imaginary_ = 0;
}

Complex::Complex(double real, double imaginary)
{
	real_ = real;
	imaginary_ = imaginary;
}

double Complex::real()
{
	return real_;
}

double Complex::imag()
{
	return imaginary_;
}

double Complex::norm()
{
	return sqrt(real_ * real_ + imaginary_ * imaginary_);
}

double real(Complex & complex1)
{
	return complex1.real_;
}

double imag(Complex & complex1)
{
	return complex1.imaginary_;
}

double norm(Complex & complex1)
{
	return sqrt(complex1.real_ * complex1.real_ + complex1.imaginary_ * complex1.imaginary_);
}

ostream & operator<<(ostream& outputStream, const Complex& complex1)
{
	outputStream << complex1.real_ << " + " << complex1.imaginary_ << "*i" << endl;
	return outputStream;
}

istream & operator>>(istream& inputStream, Complex& complex1)
{
	inputStream >> complex1.real_ >> complex1.imaginary_;
	return inputStream;
}

Complex operator+(const Complex& complex1, const Complex& complex2)
{
	return Complex(complex1.real_ + complex2.real_, complex1.imaginary_ + complex2.imaginary_);
}

Complex operator-(const Complex& complex1, const Complex& complex2)
{
	return Complex(complex1.real_ - complex2.real_, complex1.imaginary_ - complex2.imaginary_);
}

Complex operator*(const Complex& complex1, const Complex& complex2)
{
	double real = complex1.real_ * complex2.real_ - complex1.imaginary_ * complex2.imaginary_;
	double imaginary = complex1.real_ * complex2.imaginary_ + complex2.real_ * complex1.imaginary_;
	return Complex(real, imaginary);
}

Complex operator/(const Complex& complex1, const Complex& complex2)
{
	double denominator = complex2.real_ * complex2.real_ + complex2.imaginary_ * complex2.imaginary_;
	double real = (complex1.real_ * complex2.real_ + complex1.imaginary_ * complex2.imaginary_) / denominator;
	double imaginary = (complex1.imaginary_ * complex2.real_ - complex1.real_ * complex2.imaginary_) / denominator;
	return Complex(real, imaginary);
}

bool operator==(const Complex& complex1, const Complex& complex2)
{
	if (complex1.real_ == complex2.real_ && complex1.imaginary_ == complex2.imaginary_)
		return true;
	return false;
}
