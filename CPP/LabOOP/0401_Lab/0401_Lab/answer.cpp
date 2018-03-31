// Name: B10615025 ±i®Ñ»Ê
// Date: Mar. 22, 2018
// Last Update: Mar. 22, 2018
// Problem statement: ¡GFind The Number ¡uA¡v
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	string input;
	double target;

	while (getline(cin, input))
	{
		istringstream stream(input);
		vector<string> stringVector;
		vector<double> doubleVector;
		string tempString;
		double minimalDistance;
		bool firstFlag = true;

		cin >> target;

		// Ignore '\n'
		cin.ignore();

		// Convert original input to string vector and double vector
		while (stream >> tempString)
		{
			stringVector.push_back(tempString);
			doubleVector.push_back(stod(tempString));
		}

		// Initial minimalDistance
		minimalDistance = abs(doubleVector[0] - target);

		// Find the minimal distance between S in the set of double vector and target
		for (int i = 1; i < doubleVector.size(); ++i)
		{
			double distance = abs(doubleVector[i] - target);
			if (distance < minimalDistance)
			{
				minimalDistance = distance;
			}
		}

		// Output
		for (int i = 0; i < doubleVector.size(); ++i)
		{
			double distance = abs(doubleVector[i] - target);
			if (distance == minimalDistance)
			{
				if (firstFlag)
				{
					cout << stringVector[i];
					firstFlag = false;
				}
				else
				{
					cout << " + " << stringVector[i];
				}
			}
		}
		cout << endl;

		// Clear
		stringVector.clear();
		doubleVector.clear();
		stream.clear();
	}

	return 0;
}