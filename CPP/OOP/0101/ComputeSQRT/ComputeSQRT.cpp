#include <iostream>

using namespace std;

int main()
{
	double n, guess[2], r;

	// Setting cout
	cout << fixed;
	cout.precision(2);

	// Main loop
	while (cin >> n)
	{
		// Initial guess
		guess[0] = n / 2;

		while (true)
		{
			r = n / guess[0];
			guess[1] = (guess[0] + r) / 2;

			if (guess[0] - guess[1] < 0.01)
			{	
				cout << guess[1] << endl;
				break;
			}
			else
			{
				guess[0] = guess[1];
			}
		}
	}

	return 0;
}