#include <stdio.h>

int main()
{
	int dec = 0;
	while( scanf("%d", &dec) != EOF )
	{
		char output[6] = {'0', '0', '0', '0', '0', '\x00'};
		int layer = 0;
		int temp = 0;

		while(dec != 0)
		{
			temp = dec % 8;
			output[4 - layer] = (char)((int)'0' + temp);
			layer++;
			dec -= temp;
			dec /= 8;
		}
		printf("%s\n", output);
	}
	return 0;
}
