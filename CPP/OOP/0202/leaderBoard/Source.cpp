// SID: B10615025
// Date: Mar. 14, 2018
// Last Update: Mar. 10, 2018
// Problem statement: leaderBoard
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

void getHighScores(vector<string>& name, vector<int>& score)
{
	vector<string> tempName;
	vector<int> tempScore;
	string fileName, tempString;
	int tempInt, size;

	// Reading File
	cin >> fileName;

	ifstream readFile(fileName);
	if (readFile.is_open())
	{
		while (readFile >> tempString && readFile >> tempInt)
		{
			tempName.push_back(tempString);
			tempScore.push_back(tempInt);
		}
		readFile.close();
	}

	// Ranking
	size = tempScore.size();
	for (int i = 0; i < 3; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (tempScore[i] < tempScore[j])
			{
				swap(tempScore[i], tempScore[j]);
				swap(tempName[i], tempName[j]);				
			}
		}
	}

	// Output
	size = size > 3 ? 3 : size;
	for (int i = 0; i < size; ++i)
	{
		name.push_back(tempName[i]);
		score.push_back(tempScore[i]);
	}
}

int main()
{
	vector<string> name;
	vector<int> score;
	int size;

	getHighScores(name, score);

	size = name.size();
	for (int i = 0; i < size; ++i)
	{
		cout << name[i] << endl;
		cout << score[i] << endl;
	}

	return 0;
}