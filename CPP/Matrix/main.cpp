#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Matrix.h"

using namespace std;

void readMatrixFromFile(vector<vector<double>>& vvd)
{
	string filename, line;
	int count = 0;
	double t_d;

	cout << "Input Matrix Config" << endl;
	cin >> filename;

	ifstream infile(filename);

	while(getline(infile, line))
	{
		istringstream iss(line);
		vvd.push_back(vector<double>());
		while(iss >> t_d)
		{
			vvd[count].push_back(t_d);
		}
		++count;
	}

}

int main()
{
	vector<Matrix> matrixs;

	for(int i = 0; i < 2; ++i)
	{
		vector<vector<double>> vvd;

		readMatrixFromFile(vvd);

		Matrix t_m(vvd);
		matrixs.push_back(t_m);
	}

	for(int i = 0; i < (int)matrixs.size(); ++i)
	{
		cout << matrixs[i] << endl;
	}

	return 0;
}
