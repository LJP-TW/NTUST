// Name: ±i®Ñ»Ê B10615025
// Date: May. 8, 2018
// Last Update: May. 8, 2018
// Problem statement: NameSpaceTraining
#include "user.h"

namespace
{
	string username;
	bool isValid()
	{
		// exactly eight letters
		return username.size() == 8 ? true : false;
	}
}

namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!isValid());
	}
	string getUserName()
	{
		return username;
	}
}