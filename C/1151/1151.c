#include <stdio.h>
#include <math.h>

int main()
{
	double x, y, old_y;
	while( scanf(" %lf", &x) != EOF)
	{
		y = 1;
		do
		{
			old_y = y;
			y = ( x / y + y ) / 2;
		} while ( fabs( y - old_y ) >= old_y * 0.00001 );

		printf("Square root: %.5f\n", y);
	}
	return 0;
}
