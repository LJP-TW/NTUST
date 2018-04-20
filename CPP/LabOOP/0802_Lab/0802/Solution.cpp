// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 19, 2018
// Last Update: Apr. 19, 2018
// Problem statement: Searching the string
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	fstream file("Data.txt");
	string pattern, line;

	while (cin >> pattern)
	{
		bool foundFlag = false;
		vector<int> pos;
		int lineID = 1;

		while (getline(file, line))
		{
			// If find a pattern, record the position into vector
			int p = -1;
			while ((p = line.find(pattern, p + 1)) != std::string::npos)
			{
				foundFlag = true;
				pos.push_back(p + 1);
			}

			// output
			if (pos.size() != 0)
			{
				cout << "The word " << pattern << " find at line " << lineID << ", position:";
				cout << pos[0];
				for (vector<int>::iterator i = (pos.begin() + 1); i != pos.end(); ++i)
				{
					cout << ", " << *i;
				}
				cout << endl;
			}

			// clear container
			pos.clear();

			++lineID;
		}

		if (foundFlag == false)
		{
			cout << "The word " << pattern << " not exist in this file." << endl;
		}

		// rewind
		file.clear();
		file.seekg(0);
	}

	return 0;
}