// Name: ±i®Ñ»Ê B10615025
// Date: May. 8, 2018
// Last Update: May. 8, 2018
// Problem statement: NameSpaceTraining
#include "password.h"
#include <cctype>

namespace
{
	string password;
	bool isValid()
	{
		// At least 8 characters
		if (password.size() < 8)
		{
			return false;
		}

		// At least one non-letter
		for (char c : password)
		{
			if (!isalpha(c))
			{
				return true;
			}
		}
		return false;
	}
}

namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!isValid());
	}
	string getPassword()
	{
		return password;
	}
}
