#include <stdio.h>

void Fibonacci(int, int, int);

int main()
{
	int mount;
	while(scanf(" %d", &mount) != EOF)
	{
		if(mount == 0)
			printf("0\n");
		else if(mount == 1)
			printf("0 1\n");
		else
		{
			printf("0 1");
			Fibonacci(0, 1, mount - 1);
			printf("\n");
		}
	}
	return 0;
}

void Fibonacci(int last, int new, int n)
{
	if(n == 0)
		return;
	printf(" %d", last + new);
	Fibonacci(new, last + new, n - 1);
}
