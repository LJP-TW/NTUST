#define ANSWER_STEP 16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int go(char *puzzle, int row, int col, int nowR, int nowC, int step, int mode, int *answer_mount, int *answer_step, int quick_step);

int main()
{
	int row, col, flag, count, quick_step;
	int start[2] = { 0 };
	char str[] = " %d %d";

	while(scanf(str, &row, &col) != EOF)
	{

		char *puzzle = malloc(row * (col + 1) * sizeof(char));
		int *answer_step = malloc(ANSWER_STEP * sizeof(int));
		int *answer_mount = malloc(1 * sizeof(int));
		memset(answer_step, 0, ANSWER_STEP);
		*answer_mount = 0;
		quick_step = -1;
		flag = 0;
		count = 0;

		/* init */
		getchar();
		{
			int r = 0, c = 0;
			while((*(puzzle + r*(col+1) + c) = getchar()) != EOF)
			{
				if(*(puzzle + r*(col+1) + c) == '.')
				{
					start[0] = r;
					start[1] = c;
				}
				if(++c > col)
				{
					if(++r == row)
						break;
					c = 0;
				}				
			}
			if(*(puzzle + (row-1)*(col+1) + col) == EOF)
				flag = 1;
			
		}

		/* gogogo */
		go(puzzle, row, col, start[0], start[1], 0, 0, answer_mount, answer_step, quick_step);
		if(*answer_mount == 0)
			printf("No path.\n");
		else
		{
			quick_step = *(answer_step);
			for(int i = 1; i < *answer_mount; i++)
			{
				if(*(answer_step + i) < quick_step)
					quick_step = *(answer_step + i);
			}
			go(puzzle, row, col, start[0], start[1], 0, 1, answer_mount, answer_step, quick_step);
		}
		free(puzzle);
		free(answer_step);
		free(answer_mount);
		if(flag)
			break;
	}
	return 0;
}

int go(char *puzzle, int row, int col, int nowR, int nowC, int step, int mode, int *answer_mount, int *answer_step, int quick_step)
{
	int flag = 0;
	char *temp_puzzle = malloc(strlen(puzzle));
	memcpy(temp_puzzle, puzzle, strlen(puzzle));

	if(*(temp_puzzle + (nowR - 1)*(col+1) + nowC) == ' ')
	{
		*(temp_puzzle + (nowR - 1)*(col+1) + nowC) = '.';
		if(nowR - 1 == 0)
		{
			flag = 1;
		}
		else
		{
			*(temp_puzzle + (nowR - 1)*(col+1) + nowC) = '.';
			go(temp_puzzle, row, col, nowR - 1, nowC, step + 1, mode, answer_mount, answer_step, quick_step);
			*(temp_puzzle + (nowR - 1)*(col+1) + nowC) = ' ';
		}
	}
	if(*(temp_puzzle + nowR*(col+1) + (nowC + 1)) == ' ')
	{
		*(temp_puzzle + nowR*(col+1) + (nowC + 1)) = '.';
		if(nowC + 1 == col - 1)
		{
			flag = 1;
		}
		else
		{
			*(temp_puzzle + nowR*(col+1) + (nowC + 1)) = '.';
			go(temp_puzzle, row, col, nowR, nowC + 1, step + 1, mode, answer_mount, answer_step, quick_step);
			*(temp_puzzle + nowR*(col+1) + (nowC + 1)) = ' ';
		}
	}
	if(*(temp_puzzle + (nowR + 1)*(col+1) + nowC) == ' ')
	{
		*(temp_puzzle + (nowR + 1)*(col+1) + nowC) = '.';
		if(nowR + 1 == row - 1)
		{
			flag = 1;
		}
		else
		{
			*(temp_puzzle + (nowR + 1)*(col+1) + nowC) = '.';
			go(temp_puzzle, row, col, nowR + 1, nowC, step + 1, mode, answer_mount, answer_step, quick_step);
			*(temp_puzzle + (nowR + 1)*(col+1) + nowC) = ' ';
		}
	}
	if(*(temp_puzzle + nowR*(col+1) + (nowC - 1)) == ' ')
	{
		*(temp_puzzle + nowR*(col+1) + (nowC - 1)) = '.';
		if(nowC - 1 == 0)
		{
			flag = 1;
		}
		else
		{
			*(temp_puzzle + nowR*(col+1) + (nowC - 1)) = '.';
			go(temp_puzzle, row, col, nowR, nowC - 1, step + 1, mode, answer_mount, answer_step, quick_step);
			*(temp_puzzle + nowR*(col+1) + (nowC - 1)) = ' ';
		}
	}

	if(flag)
	{
		if(mode == 1 && step == quick_step)
		{
			for(int r = 0; r < row ; r++)
			{
				for(int c = 0; c < col; c++)
				{
					printf("%c", *(temp_puzzle + r*(col+1) + c));
				}
				printf("\n");
			}
		}
		
		else
		{
			*(answer_step + *(answer_mount)) = step;
			++*answer_mount;
		}
	}
	free(temp_puzzle);
	return 0;
}
