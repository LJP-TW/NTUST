// UID : B10615025
// Last Update : Mar. 17, 2018
// Problem statement : occurrencCounting

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct counter
{
	int n;
	int count;
};

int main()
{
	vector<counter> dataVector;
	int buffer;
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	// Input
	if (inputFile.is_open())
	{
		while (inputFile >> buffer)
		{
			bool found = false;

			for (int i = 0; i < dataVector.size(); ++i)
			{
				if (dataVector[i].n == buffer)
				{
					++dataVector[i].count;
					found = true;
					break;
				}
			}

			if (!found)
			{
				counter counterBuffer;
				counterBuffer.n = buffer;
				counterBuffer.count = 1;

				dataVector.push_back(counterBuffer);
			}
		}

		inputFile.close();
	}

	// Sort
	for (int i = 0; i < (int)dataVector.size() - 1; ++i)
	{
		for (int j = 1; j < (int)dataVector.size() - i; ++j)
		{
			if (dataVector[j].n > dataVector[j - 1].n)
			{
				swap(dataVector[j], dataVector[j - 1]);
			}
		}
	}

	// Output
	if (outputFile.is_open())
	{
		outputFile << "N\tCount" << endl;
		for (int i = 0; i < (int)dataVector.size(); ++i)
		{
			outputFile << dataVector[i].n << '\t' << dataVector[i].count << endl;
		}

		outputFile.close();
	}
	
	return 0;
}