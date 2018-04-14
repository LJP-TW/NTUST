// Name: �i�ѻ� B10615025
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
	void SetInputWord(string inputWord);//�]�wInput
	void SetFileName(string fileName);//�]�w�ɮצW��
	void ProcessInputWord();//�B�z Input ����T
	void Load_CompaerWord();//Ū�ɨåB���

	// Accessor
	void PrintFoundWords();//�L�X�ŦX���r

private:
	string input;//��J���r
	string fileName;//�ɮצW��
	vector<string> matchWord;//�ŦX���r
	map<char, int> inputMap;//��J�r�ꤤ�U�Ӧr���X�{����
};

#endif