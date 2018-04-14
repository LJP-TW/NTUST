// Name: ±i®Ñ»Ê B10615025
// Date: Apr. 14, 2018
// Last Update: Apr. 14, 2018
// Problem statement: FormWord
#include "FormWord.h"

Form::Form()
{
}

void Form::SetInputWord(string inputWord)
{
	this->input = inputWord;
}

void Form::SetFileName(string fileName)
{
	this->fileName = fileName;
}

void Form::ProcessInputWord()
{
	for (char i : input)
	{
		++inputMap[tolower(i)];
	}
}

void Form::Load_CompaerWord()
{
	fstream file(fileName);
	string fileStr;
	map<char, int>fileMap;
	while (getline(file, fileStr))
	{
		bool matchFlag = true;

		// convert strings in file into map
		for (char i : fileStr)
		{
			++fileMap[tolower(i)];
		}

		// Compare by using map
		for (pair<const char, const int> i : fileMap)
		{
			if (inputMap[i.first] < i.second)
			{
				matchFlag = false;
				break;
			}
		}

		if (matchFlag)
		{
			matchWord.push_back(fileStr);
		}

		fileMap.clear();
	}
}

void Form::PrintFoundWords()
{
	for (string i : matchWord)
	{
		cout << i << endl;
	}
}
