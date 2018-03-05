#include <stdio.h>

int f(int);
int g(int);

int main()
{
	int n;
	while(scanf(" %d", &n) != EOF)
	{
		if(n % 2 == 0)
			printf("(%d,%d,%d)\n", f(n), g(n), (f(n)+g(n)) > 0?(f(n)+g(n)):-(f(n)+g(n)));
		else
			printf("(%d,%d,%d)\n", f(n), g(n), (f(n)+g(n)) > 0?(f(n)-g(n)):-(f(n)-g(n)));
	}
	return 0;
}

int f(int n)
{
	if(n == 0 || n == 1)
		return 1;
	return f(n/2) + f(n/2 - 1);
}

int g(int n)
{
	if(n == 0 || n == 1 || n == 2)
		return n;
	return g(n/2) + g(n/3);
}
