#include <stdio.h>
#include <string.h>
#define NUM_MOUNT 7

void printPhoneWord(int);
char dictionary[8][3] = {{'A', 'B', 'C'},
			 {'D', 'E', 'F'},
			 {'G', 'H', 'I'},
			 {'J', 'K', 'L'},
			 {'M', 'N', 'O'},
			 {'P', 'R', 'S'},
			 {'T', 'U', 'V'},
			 {'W', 'X', 'Y'}};
char output[8] = { 0 };
int validNum[NUM_MOUNT][2] = {{ 0 }}; // validNum[Num][Dictionary_Index]
int validNumMount = 0;

int main()
{
	char str[101] = { 0 };
	int flag = 0;

	while(fgets(str, 101, stdin) != NULL)
	{
		/* debug */
		//printf("strlen : %d : %s", (int)strlen(str), str);
		
		/* Init */
		for(int i = 0; i < 8; i++)
			output[i] = 0;
		for(int i = 0; i < NUM_MOUNT; i++)
			for(int j = 0; j < 2; j++)
				validNum[i][j] = -1;
		validNumMount = 0;
		flag = 0;
		
		/* Set validNum */
		for(int i = 0; i < (int)strlen(str); i++)
		{
			if(str[i] == '0' || str[i] == '1')
			{
				flag = 1;
				break;
			}
			if(str[i] >= '2' && str[i] <= '9')
			{
				validNum[validNumMount][0] = (int)str[i] - (int)'2';
				validNum[validNumMount][1] = 0;
				++validNumMount;
				if(validNumMount == NUM_MOUNT)
					break;
			}
		}
		/* debug */
		/*
		for(int i = 0; i < NUM_MOUNT; i++)
		{
			for(int j = 0; j < 2; j++)
				printf("%4d", validNum[i][j]);
			printf("\n");
		}
		printf("\n");
		*/

		/* Output */
		if(flag)
		{
			printf("Can't print a word!\n");
			continue;
		}
		if(validNum[0][0] == -1)
		{
			printf("None.\n");
			continue;
		}
		printPhoneWord(0);	
			
		for(int i = 0; i < 101; i++)
			str[i] = 0;
		
	}
	return 0;
}

void printPhoneWord(int layer)
{
	if(layer == validNumMount)
		return;
	while(validNum[layer][1] < 3)
	{
		output[layer] = dictionary[validNum[layer][0]][validNum[layer][1]];
		printPhoneWord(layer + 1);
		if(layer == validNumMount - 1)
		{
			printf("%s\n", output);
		}
		validNum[layer][1]++;
	}
	validNum[layer][1] = 0;
	return;
}
