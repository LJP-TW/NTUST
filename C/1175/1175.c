#include <stdio.h>
#include <string.h>
#define MAX_INPUT_LENGTH 100


int main()
{
	char input[MAX_INPUT_LENGTH + 1] = { 0 };
	char validInput[MAX_INPUT_LENGTH + 1] = { 0 };
	int validInputLength = 0;
	char sevenSegment[10][3][4] = {	{" _ ",
					 "| |",
					 "|_|"},
	       				{"   ",
					 "  |",
					 "  |"},
	     				{" _ ",
					 " _|",
					 "|_ "},
					{" _ ",
					 " _|",
					 " _|"},
					{"   ",
					 "|_|",
					 "  |"},
					{" _ ",
					 "|_ ",
					 " _|"},
					{" _ ",
					 "|_ ",
					 "|_|"},
					{" _ ",
					 "  |",
					 "  |"},
					{" _ ",
					 "|_|",
					 "|_|"},
					{" _ ",
					 "|_|",
					 " _|"}};


	while(fgets(input, MAX_INPUT_LENGTH + 1, stdin) != NULL)
	{
		/* Init */
		for(int i = 0; i <= MAX_INPUT_LENGTH; i++)
		{
			if(input[i] >= '0' && input[i] <= '9')
			{
				validInput[validInputLength] = input[i];
				++validInputLength;
			}
		}
		
		/* debug */
		//printf("%s\n", sevenSegment[0][0]);
		//printf("%s\n", sevenSegment[0][1]);
		//printf("%s\n", sevenSegment[0][2]);
		//printf("yee %d\n", input_length);
		//for(int i = 0; i < validInputLength; i++)
		//{
		//	printf("%4d", validInput[i] - (int)'0');
		//}

		/* Output */
		for(int layer = 0; layer < 3; layer++)
		{
			for(int i = 0; i < validInputLength; i++)
			{
				printf("%s", sevenSegment[validInput[i] - (int)'0'][layer]);
			}
			printf("\n");
		}

		/* Clear Array */
		for(int i = 0; i <= MAX_INPUT_LENGTH; i++)
		{
			input[i] = 0;
			validInput[i] = 0;
			validInputLength = 0;
		}
	}

	return 0;
}
