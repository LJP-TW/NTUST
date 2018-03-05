#include <stdio.h>

int main()
{
	int n[4], max, min;
	while(scanf(" %d %d %d %d", &n[0], &n[1], &n[2], &n[3]) != EOF)
	{
		if(n[0] >= n[1] && n[0] >= n[2] && n[0] >= n[3])
		{
			max = n[0];
		}
		else if(n[1] >= n[0] && n[1] >= n[2] && n[1] >= n[3])
		{
			max = n[1];
		}
		else if(n[2] >= n[0] && n[2] >= n[1] && n[2] >= n[3])
		{
			max = n[2];
		}
		else if(n[3] >= n[0] && n[3] >= n[1] && n[3] >= n[2])
		{
			max = n[3];
		}

		if(n[0] <= n[1] && n[0] <= n[2] && n[0] <= n[3])
		{
			min = n[0];
		}
		else if(n[1] <= n[0] && n[1] <= n[2] && n[1] <= n[3])
		{
			min = n[1];
		}
		else if(n[2] <= n[0] && n[2] <= n[1] && n[2] <= n[3])
		{
			min = n[2];
		}
		else if(n[3] <= n[0] && n[3] <= n[1] && n[3] <= n[2])
		{
			min = n[3];
		}

		printf("Largest: %d\n", max);
		printf("Smallest: %d\n", min);
		
	}
	return 0;
}
