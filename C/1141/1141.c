#include <stdio.h>

int main()
{
	int grade;
	while(scanf(" %d", &grade) != EOF)
	{
		if(grade < 0 || grade > 100)
		{
			printf("Error!\n");
			continue;
		}

		if(grade >= 90)
			printf("Letter grade: A\n");
		else if(grade >= 80)
			printf("Letter grade: B\n");
		else if(grade >= 70)
			printf("Letter grade: C\n");
		else if(grade >= 60)
			printf("Letter grade: D\n");
		else
			printf("Letter grade: F\n");
	}
	return 0;
}
