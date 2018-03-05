#include <stdio.h>

int main()
{
	int num = 0;
	while( scanf("%d", &num) != EOF )
	{
		char result[3] = "";
		result[0] = (int)'0' + ( num % 10 );
		result[1] = (int)'0' + ( num / 10 );
		printf("%s\n", result);
	}
	return 0;
}
