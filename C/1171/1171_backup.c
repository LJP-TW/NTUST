#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRING_LENGTH 256
#define TABLE_SIZE 256

void makeMatrix(int, int);
int min(int, int, int);
char str1[STRING_LENGTH] = { 0 };
char str2[STRING_LENGTH] = { 0 };
int num_table[TABLE_SIZE][TABLE_SIZE] = {{ 0 }};
int distance = 0;
int lenStr1, lenStr2;

int main()
{
	while(gets(str1) != EOF)
	{
		gets(str2);
		lenStr1 = (int)strlen(str1);
		lenStr2 = (int)strlen(str2);
		distance = 0;

		/* Create table */
		for(int i = 0; i < lenStr2; i++)
			for(int j = 0; j < lenStr1; j++)
				num_table[i][j] = 0;	
		for(int i = 1; i <= lenStr1; i++)
			num_table[0][i] = i;
		for(int i = 1; i <= lenStr2; i++)
			num_table[i][0] = i;

		/* debug */
		/*
		for(int i = 0; i <= lenStr2; i++)
		{
			for(int j = 0; j <= lenStr1; j++)
				printf("%4d", num_table[i][j]);
			printf("\n");
		}
		*/	

		/* debug */
		/*
		printf("%s\n", str1);
		printf("%s\n", str2);
		*/
		
		makeMatrix(0, 0);

		/* debug */
		/*
		for(int i = 0; i <= lenStr2; i++)
		{
			for(int j = 0; j <= lenStr1; j++)
				printf("%4d", num_table[i][j]);
			printf("\n");
		}	
		*/		

		printf("Distance = %d\n", num_table[lenStr2][lenStr1]);	
		for(int i = 0; i < STRING_LENGTH; i++)
		{
			str1[i] = 0;
			str2[i] = 0;
		}
	}
	return 0;
}

void makeMatrix(int nowRow, int nowCol)
{
	if(nowRow == lenStr2)
		return;
	/* give value to (x+1, y+1) */
	/* debug */
	//printf("%c vs %c (%d, %d)\n", str1[nowCol], str2[nowRow], nowCol, nowRow);

	if(str1[nowCol] == str2[nowRow])
	{
		/* debug */
		/*
		printf("same!\n");
		printf("(%d, %d) = min(%d, %d, %d)\n",nowRow + 1, nowCol + 1, num_table[nowRow][nowCol], num_table[nowRow + 1][nowCol] + 1, num_table[nowRow][nowCol + 1] + 1);
		*/
		num_table[nowRow + 1][nowCol + 1] = min(num_table[nowRow][nowCol], num_table[nowRow + 1][nowCol] + 1, num_table[nowRow][nowCol + 1] + 1);
	}
	else
	{
		/* debug */
		/*
		printf("not same!\n");
		printf("(%d, %d) = min(%d, %d, %d)\n",nowRow + 1, nowCol + 1, num_table[nowRow][nowCol] + 1, num_table[nowRow + 1][nowCol] + 1, num_table[nowRow][nowCol + 1] + 1);
		*/
		num_table[nowRow + 1][nowCol + 1] = min(num_table[nowRow][nowCol] + 1, num_table[nowRow + 1][nowCol] + 1, num_table[nowRow][nowCol + 1] + 1);
	}
	/* recursion */
	if(nowCol == lenStr1 - 1)
		makeMatrix(nowRow + 1, 0);
	else
		makeMatrix(nowRow, nowCol + 1);
}

int min(int n1, int n2, int n3)
{
	if(n1 <= n2 && n1 <= n3)
		return n1;
	if(n2 <= n1 && n2 <= n3)
		return n2;
	return n3;
}
