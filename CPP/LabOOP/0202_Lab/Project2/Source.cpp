// SID: B10615025
// Date: Mar. 8, 2018
// Last Update: Mar. 8, 2018
// Problem statement: 02- Sketch the Edge
#include <iostream>

using namespace std;

int main()
{
	int columnHeight[1024] = { 0 }, left = 1024, right = 0;
	int leftCoordinate, rightCoordinate, h;
	
	while (cin >> leftCoordinate >> h >> rightCoordinate)
	{
		// Update columnHeight, left, right
		for (int i = leftCoordinate; i < rightCoordinate; ++i)
		{
			if (columnHeight[i] < h)
			{
				columnHeight[i] = h;
			}
			if (left > leftCoordinate)
			{
				left = leftCoordinate;
			}
			if (right < rightCoordinate)
			{
				right = rightCoordinate;
			}
		}
	}

	// Output
	cout << left << " ";
	cout << 0 << " ";
	cout << left << " ";
	cout << columnHeight[left] << " ";

	for (int i = left + 1; i < right; ++i)
	{
		if (columnHeight[i] != columnHeight[i - 1])
		{
			cout << i << " ";
			cout << columnHeight[i - 1] << " ";
			cout << i << " ";
			cout << columnHeight[i] << " ";
		}
	}

	cout << right << " ";
	cout << columnHeight[right - 1] << " ";
	cout << right << " ";
	cout << 0 << " ";

	return 0;
}