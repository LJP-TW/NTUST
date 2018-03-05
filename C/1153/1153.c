#include <stdio.h>
#include <math.h>

int main()
{
	unsigned char flag;
	int mode, n1;
	int prime_table[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	char *prime_table2[8] = {"2", "6", "120", "5040", "39916800", "6227020800", "355687428096000", "121645100408832000"};
	while( scanf(" %d %d", &mode, &n1) != EOF)
	{	
		flag = 1;
		if(mode)
		{
			for(int i = 0; i < 8; i++)
			{
				if(prime_table[i] <= n1)
					printf("%d! = %s\n", prime_table[i], prime_table2[i]);
			}
		}
		else
		{
			for(int i = 0; i <= n1; i++)
			{
				if( i <= 20)
				{
					for(int j = 0; j < 8; j++)
					{
						if(i == prime_table[j])
							printf("%d\n", i);
					}
				}
				else
				{
					//printf("judge %d\n", i);
					if(i % 2 == 0)
						continue;
					else if(i % 3 == 0)
						continue;
					for(int j = 5; j <= sqrt(i); j += 6)
					{
						flag = 1;
						//printf("%d %% %d == %d\n", i, j, i % j);
						if(i % j == 0 || i % (j+2) == 0)
						{
							flag = 0;
							break;
						}
					}
					if(flag)
						printf("%d\n", i);

				}
			}
		}
	}
	return 0;
}
