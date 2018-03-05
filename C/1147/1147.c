#include <stdio.h>

int main()
{
	int n[2], temp;
	while( scanf(" %d %d", &n[0], &n[1]) != EOF )
	{
		if( n[0] <= 0 || n[1] <= 0)
		{
			printf("The number must be positive!!!\n");
			continue;
		}
		
		while( n[0] != 0)
		{
			/* n[0] always bigger then n[1] */
			if(n[0] < n[1])
			{
				temp = n[0];
				n[0] = n[1];
				n[1] = temp;
			}

			n[0] %= n[1];	
		}

		printf("%d\n", n[1]);
	}
	return 0;
}
