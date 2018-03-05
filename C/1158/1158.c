#include <stdio.h>
#include <string.h>
#define length 300

int main()
{
	char str[length] = { 0 };
	char output[20] = { 0 };
	int number_table[10] = { 0 }, flag;
	while( scanf(" %s", str) != EOF)
	{
		for(int i = 0; i < 10; i++)
			number_table[i] = 0;
		for(int i = 0; i < 20; i++)
			output[i] = 0;

		for(int i = 0; i < (int)strlen(str); i++)
			++number_table[str[i] - '0'];

		flag = 0;
		for(int i = 0; i < 10; i++)
		{
			if(number_table[i] > 1)
			{
				if(flag)
					output[flag++] = ' ';
				output[flag++] = i + '0';
			}
		}
		if(flag)
			printf("%s\n", output);
		else
			printf("No repeated digit.\n");

		for(int i = 0; i < length; i++)
			str[i] = 0;
	}
	return 0;
}
