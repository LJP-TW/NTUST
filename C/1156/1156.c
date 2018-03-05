#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[100] = { ' ' };
	int count[26] = { 0 }, flag;
	while( scanf(" %s", str) != EOF)
	{
		for(int i = 0; i < (int)strlen(str); i++)
			++count[tolower(str[i]) - 'a'];
		

		scanf(" %s", str);
		for(int i = 0; i < (int)strlen(str); i++)
			--count[tolower(str[i]) - 'a'];

		flag = 1;
		for(int i = 0; i < 26; i++)
		{
			if(count[i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("The word are anagrams.\n");
		else
			printf("The word are not anagrams.\n");
		for(int i = 0; i < 100; i++)
			str[i] = ' ';
		for(int i = 0; i < 26; i++)
			count[i] = 0;
	}
	return 0;
}
