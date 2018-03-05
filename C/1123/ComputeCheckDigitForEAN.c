#include <stdio.h>

int main()
{
	char ean[13] = "";
	while( scanf("%s", ean) != EOF )
	{
		int sumOdd = 0, sumEven = 0, sum = 0;
		for(int i = 0; i <= 5; i++ )
		{
			sumOdd += (int)ean[i*2] - (int)'0';
			sumEven += (int)ean[i*2 + 1] - (int)'0';
		}
		sum = sumEven * 3 + sumOdd - 1;
		sum %= 10;
		sum = 9 - sum;
		printf("%d\n", sum);
	}

	return 0;
}
