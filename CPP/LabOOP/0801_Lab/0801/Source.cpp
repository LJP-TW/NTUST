// Name: 張書銘 B10615025
// Date: Apr. 19, 2018
// Last Update: Apr. 19, 2018
// Problem statement: 陣列應用
#include <iostream>

using namespace std;

int main()
{
	int a, b, n, r;

	while (cin >> a >> b >> n)
	{
		// output quotient
		cout << a / b;

		// save remainder
		r = a % b;

		if (n != 0)
		{
			cout << ".";
		}

		// output to n decimal places
		for (int i = 0; i < n; ++i)
		{
			r *= 10;
			cout << r / b;
			r %= b;
		}

		cout << endl;
	}
}