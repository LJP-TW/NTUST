#include <stdio.h>

int main()
{
	long int word, count;
	char ch, split_flag;
	while((ch = getchar()) != EOF )
	{
		if(ch >= 33 && ch <= 126)
		{
			word = 1;
			count = 1;
			split_flag = 0;
		}
		else
		{
			word = 0;
			count = 0;
			split_flag = 1;
		}

		while((ch = getchar()) != '\n')
		{
			if(ch >= 33 && ch <= 126)
			{
				++word;
				if(split_flag)
					++count;
				split_flag = 0;
			}
			else
				split_flag = 1;
		}
		
		printf("Average word length: %.1f\n", count?(double)word / count:0);
	}
	return 0;
}
