#include <stdio.h>

int main()
{
	int n;
	double sum, denominator;
	while(scanf(" %d", &n) != EOF)
	{
		sum = 1;
		denominator = 1;
		for(int i = 0; i < n; i++)
		{
			denominator *= (i+1);
			sum += 1.0 / denominator;
		}
		printf("%f\n", sum);
	}
	return 0;
}
