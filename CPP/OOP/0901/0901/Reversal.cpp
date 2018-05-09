// Name: ±i®Ñ»Ê B10615025
// Date: Mar. 8, 2018
// Last Update: Mar. 8, 2018
// Problem statement: Reversal
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
//#define DEBUG

#ifdef DEBUG
#include <ctime>
#endif

using namespace std;

int main()
{	
#ifdef DEBUG
	// Timer
	clock_t timerStart = clock();
#endif
	
	fstream file("words.txt");
	map<string, int> wordsMap;
	vector<string> wordsVector;
	string line;
	int length = 0, idx = -1;
	int i = 0;

	// Read File
	while (file >> line)
	{
		string tolowerLine = line;
		transform(tolowerLine.begin(), tolowerLine.end(), tolowerLine.begin(), tolower);
		
		// If and only if it is not exist, it will be inserted into map
		map<string, int>::iterator search = wordsMap.find(tolowerLine);
		if (search == wordsMap.end())
		{
			wordsMap[tolowerLine] = i++;
			wordsVector.push_back(line);
		}		
	}

	// Find
	for (pair<string, int> i : wordsMap)
	{
		string temp = i.first;

		// If temp is less than result, just skip it.
		if (temp.size() < length)
		{
			continue;
		}
		
		reverse(temp.begin(), temp.end());

		map<string, int>::iterator search = wordsMap.find(temp);
		if (search != wordsMap.end() && (temp.size() > length || (idx == -1 || i.second < idx)))
		{
			length = i.first.size();
			idx = i.second;
		}
	}

	cout << wordsVector[idx] << endl;

#ifdef DEBUG
	// Timer
	clock_t timerEnd = clock();
	cout << "cost time : " << (double) (timerEnd - timerStart) / CLOCKS_PER_SEC << "ms" << endl;
#endif

	system("pause");
	
	return 0;
}