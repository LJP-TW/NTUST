#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int stateNum, inNum, outNum;
vector<string> stateNames;

string intToBinStr(int num, int digit)
{
	string r = "", result = "";

	while (num)
	{
		r += num % 2 ? '1' : '0';
		num /= 2;
	}

	for (int i = digit - r.length(); i > 0; --i)
	{
		r += '0';
	}

	for (int i = r.length() - 1; i >= 0; --i)
	{
		result += r[i];
	}

	return result;
}

int main(int argc, char *argv[])
{
	ofstream file;
	
	file.open(argv[1]);

	// rand
	srand(time(NULL));
	stateNum = rand() % 5 + 6;
	inNum = rand() % 3 + 1;
	outNum = rand() % 3 + 1;

	for (int i = 0; i < stateNum; ++i)
	{
		string s = "S";
		s += ('A' + i);
		stateNames.push_back(s);
	}

	// Generate
	file << ".start_kiss" << endl;
	file << ".i " << inNum << endl;
	file << ".o " << outNum << endl;
	file << ".p " << stateNum * pow(2, inNum) << endl;
	file << ".s " << stateNum << endl;
	file << ".r " << stateNames[0] << endl;

	for (int i = 0; i < stateNum; ++i)
	{
		for (int j = 0; j < pow(2, inNum); ++j)
		{
			int nextState = rand() % stateNum;
			int output = rand() % (int)pow(2, outNum);
			file << intToBinStr(j, inNum) << ' ' << stateNames[i] << ' ' << stateNames[nextState] << ' ' << intToBinStr(output, outNum) << endl;
		}
	}

	file << ".end_kiss" << endl;
}