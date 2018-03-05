#include <stdio.h>

int main()
{
	int people[38] = { 0 };
	int n;
	int nextPeople;
	int order;
	int flag;
	while(scanf(" %d", &n) != EOF)
	{
		order = 1;
		nextPeople = -1;
		for(int i = 0; i < 38; i++)
			people[i] = 0;

		do{
			flag = n;
			while(flag)
			{
				if(nextPeople + 1 >= 38)
					nextPeople = 0;
				else
					nextPeople += 1;
				
				if(people[nextPeople] == 0)
					flag -= 1;
			}
			people[nextPeople] = order;
			++order;
		}while(order <= 38);
		
		printf("%d", people[0]);
		for(int i = 1; i < 38; i++)
		{
			printf(" %d", people[i]);
		}
		printf("\n");
		printf("%d\n", nextPeople + 1);
	}
	return 0;
}
