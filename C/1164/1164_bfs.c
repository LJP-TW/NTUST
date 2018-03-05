#define QUEUE_MAX 8192
#include <stdio.h>
#include <stdlib.h>

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int queueR[QUEUE_MAX] = { 0 };
int queueC[QUEUE_MAX] = { 0 };
int queue_front = -1;
int queue_behind = 0;
int previousTokenTable[QUEUE_MAX] = { 0 };

void BFS_makeMatrix(int *num_table, int row, int col, int nowR, int nowC);
void go(char *chr_table, int *num_table, int row, int col, int nowR, int nowC);

int main()
{
	int row, col, flag, start[2], end[2];
	char ch;
	while(scanf(" %d %d", &row, &col) != EOF)
	{
		int *num_table = malloc(row * col * sizeof(int));
		char *chr_taSble = malloc(row * col * sizeof(char));
		
		flag = 0;
		/* init */
		getchar();
		for(int r = 0; r < row; r++)
		{
			for(int c = 0; c < col; c++)
			{
				ch = getchar();
				switch(ch)
				{
					case '.':
						start[0] = r;
						start[1] = c;
						*(num_table + r*col + c) = 0;
						*(chr_table + r*col + c) = ' ';
						break;
					case '#':
						*(num_table + r*col + c) = -2;
						*(chr_table + r*col + c) = '#';
						break;
					case ' ':
						if(r == 0 || c == 0 || r == row - 1 || c == col - 1)
						{
							end[0] = r;
							end[1] = c;
						}
						*(num_table + r*col + c) = -1;
						*(chr_table + r*col + c) = ' ';
						break;
				}
			}
			ch = getchar();
			if(ch == EOF)
			{
				flag = 1;
				break;
			}
		}
		
		/* BETA simplify map */
		/*
		int surrounding_count;
		for(int r = 1; r < row - 1; r++)
		{
			for(int c = 1; c < col - 1; c++)
			{
				surrounding_count = 0;
				for(int i = 0; i < 4; i++)
				{
					if(r != start[0] || c != start[1])
					{
						//printf("debug (%d, %d) (%d, %d) %c\n", r, c, r+dr[i], c+dc[i], *(chr_table + (r+dr[i])*col + (c+dc[i])));
						if(*(chr_table + (r+dr[i])*col + (c+dc[i])) == ' ')
						{
							++surrounding_count;
						}
					}
				}
				printf("debug (%d, %d) %d\n", r, c, surrounding_count);
				if(surrounding_count == 1)
				{
					*(num_table + r*col + c) = -2;
				}
			}
		}
		*/
		
		/* debug */
		/*
		printf("main debuger start\n");
		//printf(" %d %d\n", end[0], end[1]);
		
		for(int r = 0; r < row; r++)
		{
			for(int c = 0; c < col; c++)
			{
				printf("%2d", *(num_table + r*col + c));
			}
			printf("\n");
		}
		printf("main debuger end\n");
		*/
		
		queueR[0] = start[0]; 
		queueC[0] = start[1];
		++queue_behind;
		
		++queue_front;
		BFS_makeMatrix(num_table, row, col, queueR[queue_front], queueC[queue_front]);
	
		*(chr_table + end[0]*col + end[1]) = '.';
		go(chr_table, num_table, row, col, end[0], end[1]);
		if(*(num_table + end[0]*col + end[1]) == -1)
		{
			printf("No path.\n");
		}
		else
		{
			for(int r = 0; r < row; r++)
			{
				for(int c = 0; c < col; c++)
				{
					printf("%c", *(chr_table + r*col + c));
				}
				printf("\n");
			}
		}
		
		/* debug */
		/*
		printf("main debug\n");
		for(int r = 0; r < row; r++)
		{
			for(int c = 0; c < col; c++)
			{
				printf("%2d ", *(num_table + r*col + c));
			}
			printf("\n");
		}
		printf("main debuger end\n");
		*/
		
		queue_behind = 0;
		queue_front = -1;
		free(num_table);
		free(chr_table);		
		if(flag)
			break;
	}
	return 0;
}

void BFS_makeMatrix(int *num_table, int row, int col, int nowR, int nowC)
{
	/* debug */
	/*
	printf("debug nowR %d nowC %d\n", nowR, nowC);
	printf("BFS_makeMatrix debug\n");
	for(int r = 0; r < row; r++)
	{
		for(int c = 0; c < col; c++)
		{
			printf(" %d ", *(num_table + r*col + c));
		}
		printf("\n");
	}
	*/
	int token = previousTokenTable[queue_front] + 1;
	int tempR;
	int tempC;
	for(int i = 0; i < 4; i++)
	{
		tempR = nowR + dr[i];
		tempC = nowC + dc[i];
		//printf("debug r,%d c,%d %d\n", tempR, tempC, *(num_table + tempR*col + tempC));
		if(tempR >= 0 && tempC >= 0 && tempR < row && tempC < col && *(num_table + tempR*col + tempC) == -1)
		{
			*(num_table + tempR*col + tempC) = token;
			queueR[queue_behind] = tempR;
			queueC[queue_behind] = tempC;
			previousTokenTable[queue_behind] = token;
			++queue_behind;
		}
	}
	if(queue_front < queue_behind)
	{
		++queue_front;
		BFS_makeMatrix(num_table, row, col, queueR[queue_front], queueC[queue_front]);
	}
}

void go(char *chr_table, int *num_table, int row, int col, int nowR, int nowC)
{
	int token = *(num_table + nowR*col + nowC);
	int tempR;
	int tempC;
	for(int i = 0; i < 4; i++)
	{
		tempR = nowR + dr[i];
		tempC = nowC + dc[i];
		if(tempR >= 0 && tempC >= 0 && tempR < row && tempC < col && *(num_table + tempR*col + tempC) == token - 1)
		{
			*(chr_table + tempR*col + tempC) = '.';
			go(chr_table, num_table, row, col, tempR, tempC);
			break;
		}
	}
}