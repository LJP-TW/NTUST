// SID: B10615025
// Date: Mar. 8, 2018
// Last Update: Mar. 8, 2018
// Problem statement: 02 - Triangle Area
#include <iostream>

using namespace std;

struct Point {
	double x;
	double y;
};

int main()
{
	Point point[3];
	double area;
	bool breakFlag;

	while (1)
	{
		// Read Input
		breakFlag = false;
		for (int i = 0; i < 3; ++i)
		{
			cin >> point[i].x;

			if (cin.eof())
			{
				breakFlag = true;
			}

			cin >> point[i].y;
		}
		if (breakFlag)
		{
			break;
		}

		// Process
		area = abs(((point[0].x - point[2].x) * (point[1].y - point[0].y) - (point[0].x - point[1].x) * (point[2].y - point[0].y)) / 2);
		
		cout << fixed;
		cout.precision(2);
		cout << area << endl;
	}

	return 0;
}