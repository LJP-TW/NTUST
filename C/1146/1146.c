#include <stdio.h>

int main()
{
	double max, temp;
	while( scanf(" %lf", &temp) != EOF)
	{
		if( temp <= 0 ) 
		{
			printf("Nothing...\n");
			continue;
		}

		max = 0;

		while( temp > 0 )
		{
			if(temp > max)
				max = temp;
			scanf(" %lf", &temp);
		}

		printf("%f\n", max);
	}

	return 0;
}
