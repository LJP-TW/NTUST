#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

struct matrixSize
{
	int m;
	int n;
};

class Matrix
{
public:
	// m x n Matrix
	Matrix();
	template<int m, int n>
	Matrix(double element[m][n]);
	Matrix(vector<vector<double>>& element);

	friend ostream& operator<<(ostream& output, const Matrix& matrix)
	{
		for(int h = 0; h < matrix.m_size.m; ++h)
		{
			for(int w = 0; w < matrix.m_size.n; ++w)
			{
				output << matrix.m_matrix[h][w] << " ";
			}
			output << endl;
		}
		return output;
	}

	Matrix operator+(Matrix& addend)
	{
		Matrix augend = *this;
		for(int h = 0; h < m_size.m; ++h)
		{
			for(int w = 0; w < m_size.n; ++w)
			{
				augend.m_matrix[h][w] += addend.m_matrix[h][w];
			}
		}
		return augend;
	}

	matrixSize getSize();

private:
	matrixSize m_size;
	vector<vector<double>> m_matrix;
	

};

#endif
