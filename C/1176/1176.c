#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

long int factorial(int);

int main()
{
	/* debug */
	//printf("%d\n", factorial(5));
	
	char mode[128] = { 0 };
	double degree = 0;
	double radian = 0;
	double answer = 0;
	int n = 0;
	int quadrant = 0;

	while(scanf(" %s", mode) != EOF)
	{
		for(int i = 0; i < (int)strlen(mode); i++)
			mode[i] = tolower(mode[i]);
		if(strcmp(mode, "sin") && strcmp(mode, "cos"))
		{
			printf("Input Error.\n");
			continue;
		}
		scanf(" %lf", &degree);
		scanf(" %d", &n);
		
		/* Init */
		while(degree < 0)
			degree += 360;		
		while(degree >= 360)
			degree -= 360;
		if(degree <= 90)
			quadrant = 1;
		else if(degree <= 180)
			quadrant = 2;
		else if(degree <= 270)
			quadrant = 3;
		else
			quadrant = 4;
		if(degree > 180)
		{
			//degree = 360 - degree;
			degree -= 180;
			//radian = -(degree / 180 * 3.14);
			radian = degree / 180 * 3.14;
		}
		else if(degree == 180)
			radian = 0;
		else
			radian = degree / 180 * 3.14;
		//printf("degree %.12f, radian %.12f\n", degree, radian);
		answer = 0;

		/* Calculate */
		printf("debug -- radian : %f\n", radian);
		if(strcmp(mode, "sin") == 0)
		{
			for(int i = 0; i <= n; i++)
			{
				printf("debug1 %.12f, %.12f, %.12f\n", pow(-1, i), pow(radian, 2 * i + 1), (double)factorial(2 * i + 1));
				//printf("debug2 %.12f + %.12f = ", answer, pow(-1, i) * pow(radian, 2 * i + 1) / factorial(2 * i + 1));
				answer += pow(-1, i) * pow(radian, 2 * i + 1) / factorial(2 * i + 1);	
				//printf("%.12f\n", answer);
			}
			if(answer < 0)
				answer = -answer;
			if(quadrant == 3 || quadrant == 4)
				answer = -answer;
		}	
		else if(strcmp(mode, "cos") == 0)
		{
			for(int i = 0; i <= n; i++)
			{
				//printf("debug %.12f + %.12f = ", answer, pow(-1, i) * pow(radian, 2 * i) / factorial(2 * i));
				answer += pow(-1, i) * pow(radian, 2 * i) / factorial(2 * i);	
				//printf("%.12f\n", answer);
			}
			if(answer < 0)
				answer = -answer;
			if(quadrant == 2 || quadrant == 3)
				answer = -answer;
		}
		printf("%.6f\n", answer);
	}
	return 0;
}

long int factorial(int n)
{
	if(n == 0)
		return 1;
	return n * factorial(n - 1);
}
