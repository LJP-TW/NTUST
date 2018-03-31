#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string Factorial(int i)
{
	string f[] =
	{
		"1",
		"1",
		"2",
		"6",
		"24",
		"120",
		"720",
		"5040",
		"40320",
		"362880",
		"3628800",
		"39916800",
		"479001600",
		"6227020800",
		"87178291200"
	};

	return f[i];
}

int main()
{
	int n;
	vector<int> vectorInt;

	// Handle Input
	while (cin >> n)
	{
		vectorInt.clear();
		for (int i = 0; i < n; ++i)
		{
			int t_i;
			cin >> t_i;
			vectorInt.push_back(t_i);
		}

		// Sorting
		sort(vectorInt.begin(), vectorInt.end());

		// Output
		cout << Factorial(vectorInt[0]);
		for (int i = 1; i < n; ++i)
		{
			cout << '<' << Factorial(vectorInt[i]);
		}
		cout << endl;
	}

	return 0;
}