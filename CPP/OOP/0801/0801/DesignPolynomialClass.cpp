// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 21, 2018
// Last Update: Apr. 21, 2018
// Problem statement: Design Polynomial Class
#include "DesignPolynomialClass.h"

Polynomial::Polynomial() : size(0)
{
	coefficent = NULL;
}

Polynomial::Polynomial(double constant) : size(1)
{
	coefficent = new double[size];
	coefficent[0] = constant;
}

Polynomial::Polynomial(double coefficent[], size_t size) : size(size)
{
	this->coefficent = new double[size];
	for (int i = 0; i < size; ++i)
	{
		this->coefficent[i] = coefficent[i];
	}
}

Polynomial::Polynomial(const Polynomial& p)
{
	size = p.size;
	coefficent = new double[size];

	for (int i = 0; i < size; ++i)
	{
		coefficent[i] = p.coefficent[i];
	}
}

Polynomial::~Polynomial()
{
	delete[] coefficent;
}

Polynomial& Polynomial::operator=(const Polynomial& other)
{
	if (coefficent != NULL)
	{
		delete[] coefficent;
		coefficent = NULL;
	}

	size = other.size;
	coefficent = new double[size];

	for (int i = 0; i < size; ++i)
	{
		coefficent[i] = other.coefficent[i];
	}

	return *this;
}

double& Polynomial::operator[](size_t idx)
{
	return coefficent[idx];
}

const double& Polynomial::operator[](size_t idx) const
{
	return coefficent[idx];
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial p = p1;

	for (int i = 0; i < p.size && i < p2.size; ++i)
	{
		p.coefficent[i] += p2.coefficent[i];
	}

	// If p2 size is bigger than p1,
	// assign a bigger memory for p1,
	// copy old value of p1 to new p1,
	// and than continue to operate p1 with p2
	if (p2.size > p.size)
	{
		size_t oldSize = p.size;

		p.resize(p2.size);
		
		// continue to operate
		for (int i = oldSize; i < p2.size; ++i)
		{
			p.coefficent[i] += p2.coefficent[i];
		}
	}

	return p;
}

Polynomial operator-(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial p = p1;

	for (int i = 0; i < p.size && i < p2.size; ++i)
	{
		p.coefficent[i] -= p2.coefficent[i];
	}

	// If p2 size is bigger than p1,
	// assign a bigger memory for p1,
	// copy old value of p1 to new p1,
	// and than continue to operate p1 with p2
	if (p2.size > p.size)
	{
		size_t oldSize = p.size;

		p.resize(p2.size);

		// continue to operate
		for (int i = oldSize; i < p2.size; ++i)
		{
			p.coefficent[i] -= p2.coefficent[i];
		}
	}

	return p;
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial p;

	// If p1 or p2 is empty, just return empty as well
	if (p1.coefficent == NULL || p2.coefficent == NULL)
	{
		return p;
	}

	// new size 
	// = new degree + 1 
	// = (p1 degree + p2 degree) + 1
	// = (p1 size - 1 + p2 size - 1 ) + 1
	// = p1 size + p2 size - 1
	p.resize(p1.size + p2.size - 1);

	for (int i = 0; i < p1.size; ++i)
	{
		for (int j = 0; j < p2.size; ++j)
		{
			p.coefficent[i + j] += p1.coefficent[i] * p2.coefficent[j];
		}
	}

	return p;
}

double evaluate(Polynomial& p, double x)
{
	double value = 0;
	for (int i = 0; i < p.size; ++i)
	{
		double temp = p.coefficent[i];
		for (int power = i; power > 0; --power)
		{
			temp *= x;
		}
		value += temp;
	}
	return value;
}

void Polynomial::resize(size_t newSize)
{
	double* oldCoe = coefficent;
	size_t oldSize = size;

	coefficent = new double[newSize];
	size = newSize;

	for (int i = 0; i < oldSize && i < size; ++i)
	{
		coefficent[i] = oldCoe[i];
	}

	for (int i = oldSize; i < size; ++i)
	{
		coefficent[i] = 0;
	}

	delete[] oldCoe;
}

size_t Polynomial::mySize()
{
	return size;
}