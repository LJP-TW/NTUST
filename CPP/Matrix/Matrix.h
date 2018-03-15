#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
	// m x n Matrix
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


private:
	int m_m, m_n; // m x n Matrix
	vector<vector<double>> m_matrix;
	

};

#endif
