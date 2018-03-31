// UID : B10615025
// Last Update : Mar. 17, 2018
// Problem statement : textBasedHistogram

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int grade[6] = { 0 }, buffer;
	ifstream inputFile("grade.txt");
	ofstream outputFile("grades.Outupt");

	// Input
	if (inputFile.is_open())
	{
		while (inputFile >> buffer)
		{
			++grade[buffer];
		}

		inputFile.close();
	}

	// Output
	if (outputFile.is_open())
	{
		for (int i = 0; i < 6; ++i)
		{
			outputFile << grade[i] << " grade(s) of " << i << endl;
		}

		outputFile.close();
	}

	return 0;
}