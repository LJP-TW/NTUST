#include <stdio.h>

int main()
{
	int n[3], _n[3], space1, space2, temp;
	while(scanf(" %d %d %d", &n[0], &n[1], &n[2]) != EOF)
	{
		space1 = 0;
		space2 = 0;

		for(int i = 0; i < 3; i++)
			_n[i] = n[i];

		for(int i = 0; i < 2; i++)
		{
			space1 += ((n[i] - n[i+1]) > 0)	?n[i] - n[i+1]
							:n[i+1] - n[i];

		}
		
		for(int i = 2; i > 0; i--)
		{
			for(int j = 0; j < i; j++)
			{
				if(_n[j] < _n[j+1])
				{
					temp = _n[j+1];
					_n[j+1] = _n[j];
					_n[j] = temp;
				}
			}
		}
		space2 += _n[0] - _n[2];

		printf("%d %d %d %d\n", n[0], n[1], n[2], space1);
		printf("%d %d %d %d\n", _n[0], _n[1], _n[2], space2);
	}
	return 0;
}
