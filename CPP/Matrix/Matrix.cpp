#include "Matrix.h"

Matrix::Matrix()
{
	m_m = 0;
	m_n = 0;
}

template<int m, int n>
Matrix::Matrix(double element[m][n])
{
	m_m = m;
	m_n = n;
	
	// Set the size of m_matrix
	for(int h = 0; h < m; ++h)
	{
		m_matrix.push_back(vector<double>());
		for(int w = 0; w < n; ++w)
		{
			m_matrix[h].push_back(element[h][w]);
		}
	}
}

Matrix::Matrix(vector<vector<double>>& element)
{
	m_m = element.size();
	m_n = element[0].size();
	m_matrix = element;
}
