#include <stdio.h>

int main()
{
	float money;
	double tax;
	while( scanf(" %f", &money) != EOF)
	{
		if(money <= 0)
		{
			tax = 0;
		}
		else if(money <= 750)
		{
			tax = money * 0.01;
		}
		else if(money <= 2250.0)
		{
			tax = (money - 750) * 0.02 + 7.5;
		}
		else if(money <= 3750)
		{
			tax = (money - 2250) * 0.03 + 37.5;
		}
		else if(money <= 5250)
		{
			tax = (money - 3750) * 0.04 + 82.5;
		}
		else if(money <= 7000)
		{
			tax = (money - 5250) * 0.05 + 142.5;
		}
		else if(money > 7000)
		{
			tax = (money - 7000) * 0.06 + 230;
		}
		printf("%.2lf\n", tax);
	}
	return 0;
}