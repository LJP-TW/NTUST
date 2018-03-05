#include <stdio.h>
#include <stdlib.h>
#define LEN 200


int xy[2][2] = { 0 };
int go = 0;
char min[LEN][LEN];
char out[LEN][LEN];
int x = 0;
int y = 0;
int ckk = 0;

void walk(int x, int y, int, int);
void maze();

int main()
{
	while (scanf("%d%d", &y, &x) != EOF)
	{
		for (int i = 0; i < y; i++)
		{
			for (int k = 0; k < x; k++)
			{
				min[i][k] = getchar();
				if (min[i][k] == '\n')
				{
					min[i][k] = NULL;
					k--;
				}
				if (min[i][k] == '#')
				{
					min[i][k] = '2';
				}
				if (min[i][k] == '.')
				{
					min[i][k] = '1';
					xy[0][0] = i;
					xy[0][1] = k;
				}
				if ((i == 0 || i == y - 1) || (k == 0 || k == x-1))
				{
					if (min[i][k] == ' ')
					{
						xy[1][0] = i;
						xy[1][1] = k;
						min[i][k] = '0';
					}
				}
				if (min[i][k] == ' ')
				{
					min[i][k] = '0';
				}
			}
		}

		walk(xy[0][0], xy[0][1], x, y);

		if (ckk == 0)
		{
			printf("No path.\n");
		}
		else
		{
			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					printf("%c",out[i][j]);
				}
				printf("\n");
			}
			ckk = 0;
		}
		go = 0;
	}
	return 0;
}

void walk(int x, int y, int _x, int _y)
{
	/* debug */
	printf("debug\n");
	for(int i = 0; i < _y; i++)
	{
		for(int j = 0; j < _x; j++)
		{
			printf("%2c", min[i][j]);
		}
		printf("\n");
	}
	printf("debug---\n");
	
	min[x][y] = '1';
	
	if (x == xy[1][0] && y == xy[1][1])
	{
		maze();
		ckk++;
	}
	if (y < (LEN - 1) && min[x][y + 1] == '0')
	{
		walk(x, y + 1, _x, _y); 
	}
	if (x < (LEN - 1) && min[x + 1][y] == '0')
	{
		walk(x + 1, y, _x, _y); 
	}
    if (y > 0 && min[x][y - 1] == '0')
	{ 
		walk(x, y - 1, _x, _y);
	}
    if (x > 0 && min[x - 1][y] == '0')
	{ 
		walk(x - 1, y, _x, _y);
	}

	min[x][y] = '0';
}

void maze()
{
	int a, b;
	int sum = 0;
	for (a = 0; a < y; a++)
	{
		for (b = 0; b < x; b++)
		{
			if (min[a][b] == '1')
			{
				sum++;
			}
		}
	}
	if (go == 0)
	{
		go = sum;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (min[i][j] == '2')
				{
					out[i][j] = '#';
				}
				else if (min[i][j] == '1')
				{
					out[i][j] = '.';
				}
				else if (min[i][j] == '0')
				{
					out[i][j] = ' ';
				}
			}
		}
	}
	else if (sum < go)
	{
		go = sum;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (min[i][j] == '2')
				{
					out[i][j] = '#';
				}
				else if (min[i][j] == '1')
				{
					out[i][j] = '.';
				}
				else if (min[i][j] == '0')
				{
					out[i][j] = ' ';
				}
			}
		}
	}
}