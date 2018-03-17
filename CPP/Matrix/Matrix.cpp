#include "Matrix.h"

Matrix::Matrix()
{
	m_size.m = 0;
	m_size.n = 0;
}

template<int m, int n>
Matrix::Matrix(double element[m][n])
{
	m_size.m = m;
	m_size.n = n;
	
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
	m_size.m = element.size();
	m_size.n = element[0].size();
	m_matrix = element;
}

matrixSize Matrix::getSize()
{
	return m_size;
}


