/**
* Robot class testing
*/

#include <iostream>
#include "Robot.h"

using namespace std;

int main()
{
	// constructor parameters: x, y, power
	Robot roba = Robot(-11.1f, 22.2f, -33.45f);

	// constructor parameters: x, y
	// default power = 100
	Robot loba = Robot(20.f, -20.f);

	// constructor parameters: x
	// default y = 0, power = 100
	Robot *robo = new Robot(50.f);

	// default x = 0, y = 0, power = 100
	Robot *lobo = new Robot();

	// print current position x and y
	cout << roba.getX() << " , " << roba.getY() << endl;
	// print current power
	cout << roba.getPower() << endl;
	roba.move(5.5f, 2.1f);
	roba.charge(5);
	cout << roba.speak("Hello") << endl;
	// print current position x and y
	cout << roba.getX() << " , " << roba.getY() << endl;
	// print current power
	cout << roba.getPower() << endl << "======" << endl;

	cout << loba.getX() << " , " << loba.getY() << endl;
	cout << loba.getPower() << endl;
	loba.move(-60, 80);
	loba.charge(10);
	cout << loba.speak("T h E  wOrlD") << endl;
	cout << loba.getX() << " , " << loba.getY() << endl;
	cout << loba.getPower() << endl << "======" << endl;

	cout << robo->getX() << " , " << robo->getY() << endl;
	cout << robo->getPower() << endl;
	robo->move(111, 2.f);
	cout << robo->speak("heLlo 123 WORLd") << endl;
	cout << robo->getX() << " , " << robo->getY() << endl;
	cout << robo->getPower() << endl << "======" << endl;

	cout << lobo->getX() << " , " << lobo->getY() << endl;
	cout << lobo->getPower() << endl;
	lobo->move(5, 12.f);
	cout << lobo->speak("1234AbC456eDf!!") << endl;
	cout << lobo->getX() << " , " << lobo->getY() << endl;
	cout << lobo->getPower() << endl;

	system("pause");

	return 0;
}
