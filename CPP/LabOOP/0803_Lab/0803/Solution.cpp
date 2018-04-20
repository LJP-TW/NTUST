// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 19, 2018
// Last Update: Apr. 19, 2018
// Problem statement: Text repair
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	fstream inFile("Error.txt");
	ofstream outFile("Correct.txt");
	// Read file into string
	string fileStr((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());

	bool UpperFlag = true;
	for (int i = 0; i < fileStr.size(); ++i)
	{
		// If UpperFlag is True, make the char upper, and then set UpperFlag to False
		if (isalpha(fileStr[i]))
		{
			if (UpperFlag)
			{
				outFile << (char)toupper(fileStr[i]);
				UpperFlag = false;
			}
			else
			{
				outFile << (char)tolower(fileStr[i]);
			}
		}
		else
		{
			outFile << (char)fileStr[i];
			// If countering period, reset UpperFlag to True
			if (fileStr[i] == '.')
			{
				UpperFlag = true;
			}
		}
	}

	inFile.close();
	outFile.close();
	return 0;
}