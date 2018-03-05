#include <stdio.h>

int main()
{
	int array[25] = { 0 };
	int row[5] = { 0 }, column[5] = { 0 };
	while( scanf(" %d", &array[0]) != EOF)
	{
		for(int i = 1; i < 25; i++)
			scanf(" %d", &array[i]);

		for(int i = 0; i < 5; i++)
		{
			row[i] = 0;
			column[i] = 0;
		}

		for(int r = 0; r < 5; r++)
		{
			for(int c = 0; c < 5; c++)
				row[r] += array[r * 5 + c];
		}

		for(int c = 0; c < 5; c++)
		{
			for(int r = 0; r < 5; r++)
				column[c] += array[r * 5 + c];
		}

		printf("Row totals: %d %d %d %d %d\n", row[0], row[1], row[2], row[3], row[4]);
		printf("Column totals: %d %d %d %d %d\n", column[0], column[1], column[2], column[3], column[4]);
	}
	return 0;
}
