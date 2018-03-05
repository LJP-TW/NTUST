#include <stdio.h>
# define M_PI           3.14159265358979323846

int main()
{
	double r;
	double answer;

	while( scanf("%lf", &r) != EOF)
	{
		answer = 4.0 / 3.0 * M_PI * r * r * r;
		printf("%.6lf\n", answer);
	}
	return 0;
}
