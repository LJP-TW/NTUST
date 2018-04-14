// Name: 張書銘 B10615025
// Date: Apr. 14, 2018
// Last Update: Apr. 14, 2018
// Problem statement: FormWord
#ifndef FORMWORD_H
#define FORMWORD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Form
{
public:
	// Constructor
	Form();

	// Mutator
	void SetInputWord(string inputWord);//設定Input
	void SetFileName(string fileName);//設定檔案名稱
	void ProcessInputWord();//處理 Input 的資訊
	void Load_CompaerWord();//讀檔並且比較

	// Accessor
	void PrintFoundWords();//印出符合的字

private:
	string input;//輸入的字
	string fileName;//檔案名稱
	vector<string> matchWord;//符合的字
	map<char, int> inputMap;//輸入字串中各個字的出現次數
};

#endif