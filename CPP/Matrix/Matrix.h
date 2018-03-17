#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

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
		for(int h = 0; h < matrix.m_m; ++h)
		{
			for(int w = 0; w < matrix.m_n; ++w)
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
		for(int h = 0; h < m_m; ++h)
		{
			for(int w = 0; w < m_n; ++w)
			{
				augend.m_matrix[h][w] += addend.m_matrix[h][w];
			}
		}
		return augend;
	}

private:
	int m_m, m_n; // m x n Matrix
	vector<vector<double>> m_matrix;
	

};

#endif
