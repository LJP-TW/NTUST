#include <stdio.h>

int main()
{
	int m1, d1, y1, m2, d2, y2;
	while(scanf(" %d/%d/%d %d/%d/%d", &m1, &d1, &y1, &m2, &d2, &y2) != EOF)
	{
		if( m1 <= 0 || m2 <= 0 || m1 > 12 || m2 > 12)
		{
			printf("Month Error!\n");
			continue;
		}
		
		if( d1 <= 0 || d2 <= 0)
		{
			printf("Day Error!\n");
			continue;
		}

		if((m1 == 2 && (((y1 % 4 == 0) && (d1 > 29)) || ((y1 % 4 != 0) && (d1 > 28)))) ||
		   (m2 == 2 && (((y2 % 4 == 0) && (d2 > 29)) || ((y2 % 4 != 0) && (d2 > 28)))))
		{
			printf("Day Error!\n");
			continue;
		}
		
		switch(m1)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if( d1 > 31)
				{
					printf("Day Error!\n");
					continue;
				}
				break;
			case 2:
				break;
			default:
				if( d1 > 30)
				{
					printf("Day Error!\n");
					continue;
				}
				break;
		}


	}
	return 0;
}
