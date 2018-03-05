#include <stdio.h>

int main()
{
	int data_length, byte_length;
	unsigned long int sum, n;
	while( scanf(" %d %d", &byte_length, &data_length) != EOF)
	{
		sum = 0;
		for(int i = 0; i < data_length; i++)
		{
			scanf(" %lu", &n);
			sum ^= n;
		}
		switch(byte_length)
		{
			case 1:
				sum &= 0xff;
				sum = 0xff - sum;
				break;
			case 2:
				sum &= 0xffff;
				sum = 0xffff - sum;
				break;
			case 4:
				sum &= 0xffffffff;
				sum = 0xffffffff - sum;
				break;
			case 8:
				sum &= 0xffffffffffffffff;
				sum = 0xffffffffffffffff - sum;
				break;
		}
		printf("%lu\n", sum);
	}
	return 0;
}
