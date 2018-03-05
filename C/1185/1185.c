#include <stdio.h>
#include <math.h>

int isPrime(int);
void printPrime(int, int);

int main()
{
	char input[52] = { 0 };
	char test;
	int num1, num2;
	while(fgets(input, 52, stdin) != NULL)
	{
		if(sscanf(input," %i %i %c", &num1, &num2, &test) == 2)
		{
			if(num1 < 0 || num2 < 0)
				printf("Invalid input!\n");
			else
			{
				printPrime(num1, num2);
			}
		}
		else
		{
			printf("Invalid input!\n");
		}
		
	}
	return 0;
}

void printPrime(int n1, int n2)
{
	int flag = 1;
	for(int i = n1; i <= n2; i++)
	{
		if(i == 1 || i == 0)
			continue;
		else
		{
			if(isPrime(i))
			{
				if(flag)
				{
					printf("%d", i);
					flag = 0;
				}
				else
				{
					printf(", %d", i);
				}
			}
		}
			
	}
	printf("\n");
}

int isPrime(int n)
{
	if(n == 2 || n == 3 || n == 5 || n == 7)
		return 1;
	if(n % 2 == 0)
		return 0;
	if(n % 3 == 0)
		return 0;
	for(int i = 5; i <= sqrt(n); i++)
	{
		if(n % i == 0)
			return 0;
		if(n % (i + 2) == 0)
			return 0;
	}
	return 1;
}
