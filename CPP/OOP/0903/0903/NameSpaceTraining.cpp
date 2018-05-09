// Name: ±i®Ñ»Ê B10615025
// Date: May. 8, 2018
// Last Update: May. 8, 2018
// Problem statement: NameSpaceTraining
#include "password.h"
#include "user.h"

using namespace Authenticate;

int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() << " and your password is: "
		<< getPassword() << endl;
	return 0;
}
