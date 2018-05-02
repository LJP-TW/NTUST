// Name: 張書銘
// Date: Apr. 26, 2018
// Last Update: Apr. 26, 2018
// Problem statement: 我的朋友很少
#include <iostream>
//#define DEBUG

using namespace std;

int main()
{
	int n, m, q;

	while (cin >> n >> m >> q)
	{
		// Init
		int *arr = new int[n + 1];
		int index = 1;
		for (int i = 0; i < n + 1; ++i)
		{
			arr[i] = 0;
		}

		// Build
		for (; m; --m)
		{
			int a, b;
			cin >> a >> b;

			if (arr[a] == 0 && arr[b] == 0)
			{
				arr[a] = index;
				arr[b] = index;
				++index;
			}
			else if (arr[a] == 0)
			{
				arr[a] = arr[b];
			}
			else if (arr[b] == 0)
			{
				arr[b] = arr[a];
			}
			else
			{
				int keya = arr[a];
				int keyb = arr[b];
				for (int i = 0; i < n + 1; ++i)
				{
					if (arr[i] == keya || arr[i] == keyb)
					{
						arr[i] = index;
					}
				}
				++index;
			}
		}

#ifdef DEBUG
		for (int i = 0; i < n + 1; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
#endif

		// Query
		for (; q; --q)
		{
			int a, b;
			cin >> a >> b;
			if (a == b || (arr[a] == arr[b] && arr[a] != 0))
			{
				cout << ":)" << endl;
			}
			else
			{
				cout << ":(" << endl;
			}
		}

		delete[] arr;
	}

	return 0;
}