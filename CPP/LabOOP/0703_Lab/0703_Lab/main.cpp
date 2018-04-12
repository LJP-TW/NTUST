#include <iostream>
#include <string>
#include <algorithm>
#include "Rect.h" 
using namespace std;

int main()
{
	int x1, y1, width1, height1;	//for rect1
	int x2, y2, width2, height2;	//for rect2

	while (cin >> x1 >> y1 >> width1 >> height1
		>> x2 >> y2 >> width2 >> height2) {

		Rect rect1 = Rect(x1, y1, width1, height1);		//construct rect1
		Rect rect2 = Rect(x2, y2, width2, height2);		//construct rect2
		Rect unionRect = rect1 + rect2;

		cout << "union : " << unionRect.toString() << endl;

		Rect interRect = rect1 * rect2;
		cout << "intersection : " << interRect.toString() << endl;
	}
	system("pause");
	return 0;
}

