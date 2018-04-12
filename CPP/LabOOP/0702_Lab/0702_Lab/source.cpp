// Name: ±i®Ñ»Ê
// Date: Apr. 12, 2018
// Last Update: Apr. 12, 2018
// Problem statement: Vector Computation
#include <iostream>
#include "Vector.h" 
using namespace std;

int main()
{
	float x, y, k;
	while (cin >> x >> y) {
		Vector mainVector = Vector(x, y);

		cin >> x >> y;
		Vector addVector = Vector(x, y);
		Vector addResult = mainVector + addVector;

		cin >> x >> y;
		Vector subVector = Vector(x, y);
		Vector subResult = mainVector - subVector;

		cin >> x >> y;
		Vector dotVector = Vector(x, y);
		float dotResult = mainVector * dotVector;

		cin >> k;
		Vector scaleVector = mainVector * k;

		cout << "Add Result = ( " << addResult.x << " , " << addResult.y << " )" << endl;
		cout << "Subtract Result = ( " << subResult.x << " , " << subResult.y << " )" << endl;
		cout << "Dot Result = " << dotResult << endl;
		cout << "Scale Result = ( " << scaleVector.x << " , " << scaleVector.y << " )" << endl;
	}

	system("pause");
	return 0;
}
