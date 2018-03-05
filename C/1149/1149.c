#include <stdio.h>

int main()
{
	int money, fifty, ten, one;
	while(scanf(" %d", &money) != EOF)
	{
		fifty = money / 50;
		if(fifty > 3)
		{
			money -= 150;
			fifty = 3;
		}
		else
		{
			money %= 50;
		}
		
		ten = money / 10;
		if(ten > 7)
		{
			money -= 70;
			ten = 7;
		}
		else
		{
			money %= 10;
		}

		one = money;
		if(one > 10)
		{
			printf("exceed\n");
			continue;
		}
		
		printf("%d*50 + %d*10 + %d\n", fifty, ten, one);
	}
	return 0;
}
