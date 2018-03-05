#include <stdio.h>

int main()
{
	int day, week, counter;
	while(scanf(" %d %d", &day, &week) != EOF)
	{
		counter = 0;
		for(int i = 1; i < week; i++)
		{
			printf("   ");
			++counter;
		}

		for(int i = 1; i <= day; i++)
		{
			printf("%3d", i);
			++counter;

			if(counter == 7)
			{
				printf("\n");
				counter = 0;
			}
		}
		if(counter != 0)
			printf("\n");
	}
	return 0;
}
