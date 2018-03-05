#include <stdio.h>
#define DOT_MOUNT 4096

int judgement();

double dot[DOT_MOUNT][2] = {{ 0 }};
double goalDot[2] = { 0 };
int mount;

int main()
{
	while(scanf(" %d", &mount) != EOF)
	{
		for(int i = 0; i < mount ; i++)
		{
			scanf(" %lf %lf", &dot[i][0], &dot[i][1]);
		}
		scanf(" %lf %lf", &goalDot[0], &goalDot[1]);
		
		if(judgement())
		{
			printf("nyan\n");
		}
		else
		{
			printf("pasu\n");
		}		

	}

	return 0;
}

int judgement()
{
	int result = 0;
	for(int i = 0, j = mount - 1; i < mount; j = i++)
	{
		if(	(dot[i][1] > goalDot[1]) != (dot[j][1] > goalDot[1]) &&
			goalDot[0] < (dot[j][0] - dot[i][0]) * (goalDot[1] - dot[i][1]) / (dot[j][1] - dot[i][1]) + dot[i][0])
		{
			printf("yee %f %f\n", dot[i][0], dot[i][1]);
			result = ~result;
		}
	}
	return result;
}
