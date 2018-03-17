#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Matrix.h"

using namespace std;

vector<Matrix> matrixs;

void readMatrixFromFile()
{
	vector<vector<double>> vvd;
	string filename, line;
	int count = 0;
	double t_d;

	cout << "Input Matrix Config" << endl;
	cin >> filename;

	ifstream infile(filename);

	if(infile.is_open())
	{
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

		Matrix tempMatrix(vvd);
		matrixs.push_back(tempMatrix);
	}
	else
	{
		cout << "Error : File non-exist" << endl;
	}
}

void showMatrix()
{
	int index;

	cout << "Input Index : ";
	cin >> index;

	if(index >= (int)matrixs.size())
	{
		cout << "Error : Out of Range" << endl;
		return;
	}

	cout << endl << matrixs[index] << endl;
}

void addMatrix()
{
	int index1, index2;

	// Input
	cout << "Input Index1 : ";
	cin >> index1;

	if(index1 >= (int)matrixs.size())
	{
		cout << "Error : Out of Range" << endl;
		return;
	}

	cout << "Input Index2 : ";
	cin >> index2;

	if(index2 >= (int)matrixs.size())
	{
		cout << "Error : Out of Range" << endl;
		return;
	}

	// Check Size
	matrixSize m1, m2;
	m1 = matrixs[index1].getSize();
	m2 = matrixs[index2].getSize();

	if(m1.m == m2.m && m1.n == m2.n)
	{
		matrixs[index1] = matrixs[index1] + matrixs[index2];
	}
	else
	{
		cout << "Error : The size of two matrixs don't match" << endl;
	}
}

int main()
{
	bool continueFlag = true;
	while(continueFlag)
	{
		int cmd;
		cout << "1. Input Matrix from file" << endl;
		cout << "2. Show Matrix" << endl;
		cout << "3. Add two Matrix" << endl;
		cout << "4. Exit" << endl;
		cin >> cmd;

		switch(cmd)
		{
			case 1: 
				{
					readMatrixFromFile();
					break;
				}
			case 2:
				{
					showMatrix();
					break;
				}
			case 3:
				{
					addMatrix();
					break;
				}
			case 4:
				{
					cout << "Bye~" << endl;
					continueFlag = false;
					break;
				}
			default:
				{
					break;
				}
		}
	}

	return 0;
}
