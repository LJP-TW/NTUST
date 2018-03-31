// Name: ±i®Ñ»Ê B10615025
// Date: Mar. 29, 2018
// Last Update: Mar. 29, 2018
// Problem statement: Multiplication
#include <iostream>

using namespace std;

struct polynomial
{
	int coefficent[32]; // coefficent[t] is the coeffienct of x^(t)
	int max;			// max of t
};

polynomial polynomialMultiply(polynomial& p1, polynomial& p2)
{
	polynomial result;

	// Init
	for (int i = 0; i < 32; ++i)
	{
		result.coefficent[i] = 0;
	}
	result.max = 0;

	// Compute
	for (int i = p1.max; i >= 0; --i)
	{
		for (int j = p2.max; j >= 0; --j)
		{
			result.coefficent[i + j] += p1.coefficent[i] * p2.coefficent[j];
		}
	}

	for (int i = 31; i >= 0; --i)
	{
		if (result.coefficent[i] != 0)
		{
			result.max = i;
			break;
		}
	}

	return result;
}

int main()
{
	int a, b, c, d;
	polynomial origin, result;

	while (cin >> a >> b >> c >> d)
	{
		// Init
		for (int i = 0; i < 32; ++i)
		{
			origin.coefficent[i] = 0;
		}
		origin.coefficent[2] = a;
		origin.coefficent[1] = b;
		origin.coefficent[0] = c;
		origin.max = 0;
		for (int i = 31; i >= 0; --i)
		{
			if (origin.coefficent[i] != 0)
			{
				origin.max = i;
				break;
			}
		}
		result = origin;

		// Multiply
		for (int i = 1; i < d; ++i)
		{
			result = polynomialMultiply(origin, result);
		}
		if (d == 0)
		{
			result.max = 0;
			result.coefficent[0] = 1;
		}

		// Output
		cout << result.coefficent[result.max];
		for (int i = result.max - 1; i >= 0; --i)
		{
			cout << " " << result.coefficent[i];
		}
		cout << endl;
	}

	return 0;
}