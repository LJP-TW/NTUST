#include <stdio.h>
#include <string.h>
#define word_index 1024
#define word_length 256

int main()
{
	char word[word_index][word_length], lastChar;
	int count = 0;

	while( scanf(" %s", word[count]) != EOF)
	{
		lastChar = word[count][(int)strlen(word[count]) - 1];
		if(lastChar == '!' ||
		   lastChar == '?' ||
		   lastChar == '.')
		{
			word[count][(int)strlen(word[count]) - 1] = NULL;
			for(int i = count; i > 0; i--)
				printf("%s ", word[i]);
			printf("%s%c\n", word[0], lastChar);
			count = 0;
		}
		else
			++count;
	}
	return 0;
}
