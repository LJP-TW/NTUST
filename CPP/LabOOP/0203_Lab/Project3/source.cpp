// SID: B10615025
// Date: Mar. 8, 2018
// Last Update: Mar. 8, 2018
// Problem statement: 02- Exchange Foreign Currency
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string userInput;
	long long int dollar;
	int countryMount = 3;
	string country[] = 
	{
		"Japan",
		"Korean",
		"America"
	};
	string countryAbbreviation[] = 
	{
		"JYP",
		"KRW",
		"USD"
	};
	double extrangeRate[] =
	{
		3.5778,		// currencyTWDToJPY
		34.1180,	// currencyTWDToKRW
		0.0339		// currencyTWDToUSD
	};

	while (cin >> userInput)
	{
		cin >> dollar;

		for (int i = 0; i < countryMount; ++i)
		{
			if (userInput == country[i])
			{
				cout << setw(6) << "TWD" << setw(12) << countryAbbreviation[i] << endl;
				cout << setw(6) << dollar << setw(12) << (dollar * extrangeRate[i]) << endl;
				break;
			}
			if (i == countryMount - 1)
			{
				cout << "We don't provide the exchange of this country." << endl;
			}
		}
	}

	return 0;
}