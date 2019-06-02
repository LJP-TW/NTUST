#define C_VERSION

#ifdef C_VERSION
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[1024];
char output[10240];
int LPS_length[1024][1024];

void _LPS(int start, int end)
{
	if (LPS_length[start][end] != -1)
	{
		return;
	}

	if (start == end)
	{
		LPS_length[start][end] = 1;
	}
	else if (start + 1 == end && input[start] == input[end])
	{
		LPS_length[start][end] = 2;
	}
	else if (input[start] == input[end])
	{
		_LPS(start + 1, end - 1);
		LPS_length[start][end] = 2 + LPS_length[start + 1][end - 1];
	}
	else
	{
		_LPS(start + 1, end);
		_LPS(start, end - 1);
		LPS_length[start][end] = LPS_length[start + 1][end] > LPS_length[start][end - 1] ? LPS_length[start + 1][end] : LPS_length[start][end - 1];
	}
}

// Longest Palindrome Subsequences
void LPS(int start, int end)
{
	// Error
	if (end < start)
	{
		LPS_length[start][end] = 0;
		return;
	}

	// Initial LPS_Infos
	for (int i = end; i >= 0; --i)
	{
		for (int j = i; j >= 0; --j)
		{
			LPS_length[j][i] = -1;
		}
	}

	// Construct LPS_length
	_LPS(start, end);
}

void makeOutput(int start, int end)
{
	int s = start, e = end;

	char temp[512];
	char n[8];

	// Clear temp
	memset(temp, 0, 512);
	
	// Make Output
	sprintf(n, "%d", LPS_length[start][end]);
	strcat(output, n);
	strcat(output, "\n");

	while (LPS_length[s][e])
	{
		if (s == e && LPS_length[s][e] == 1)
		{
			strncat(output, &input[s], 1);
			break;
		}
		else if (s + 1 == e && LPS_length[s][e] == 2)
		{
			strncat(output, &input[s], 2);
			break;
		}
		else
		{
			if (LPS_length[start][end] % 2)
			{
				if (LPS_length[s + 1][e] % 2 == 0)
				{
					LPS_length[s + 1][e] = -1;
				}

				if (LPS_length[s][e - 1] % 2 == 0)
				{
					LPS_length[s][e - 1] = -1;
				}

				if (LPS_length[s + 1][e - 1] % 2 == 0)
				{
					LPS_length[s + 1][e - 1] = -1;
				}
			}
			else
			{
				if (LPS_length[s + 1][e] % 2 == 1)
				{
					LPS_length[s + 1][e] = -1;
				}

				if (LPS_length[s][e - 1] % 2 == 1)
				{
					LPS_length[s][e - 1] = -1;
				}

				if (LPS_length[s + 1][e - 1] % 2 == 1)
				{
					LPS_length[s + 1][e - 1] = -1;
				}
			}

			int temp_s = s;
			int temp_e = e;

			if (LPS_length[s][e - 1] >= LPS_length[s + 1][e] && LPS_length[s][e - 1] > LPS_length[s + 1][e - 1])
			{
				e -= 1;
			}
			else if (LPS_length[s + 1][e] >= LPS_length[s][e - 1] && LPS_length[s + 1][e] > LPS_length[s + 1][e - 1])
			{
				s += 1;
			}
			else
			{
				s += 1;
				e -= 1;
			}

			if (LPS_length[temp_s][temp_e] != LPS_length[s][e])
			{
				strncat(output, &input[temp_s], 1);
				strncat(temp, &input[temp_s], 1);
			}
		}
	}

	for (int i = strlen(temp); i >= 0; --i)
	{
		strncat(output, &temp[i], 1);
	}

	strcat(output, "\n");
}

int main()
{
	// Temp string space
	// How many test data
	int n;
	// Initial output
	memset(output, 0, 10240);
	while (gets(input))
	{
		n = atoi(input);
		for (; n; --n)
		{
			// Test Data String length 
			int l = -1;

			// Get Test Data String
			gets(input);

			// Get Test Data String length
			while (input[++l]);
			
			LPS(0, l - 1);

			// Make output
			makeOutput(0, l - 1);
		}
	}
	printf("%s", output);
}
#endif