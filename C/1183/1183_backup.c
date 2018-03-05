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
	double ax, ay, bx, by;
	double v1[2], v2[2];
	double cp; // Cross Product
	int flag = -1;
	for(int i = 0; i < mount; i++)
	{
		ax = dot[i][0];
		ay = dot[i][1];
		if(i + 1 >= mount)
		{
			bx = dot[0][0];
			by = dot[0][1];
		}
		else
		{
			bx = dot[i+1][0];
			by = dot[i+1][1];
		}
		v1[0] = ax - goalDot[0];
		v1[1] = ay - goalDot[1];
		v2[0] = bx - goalDot[0];
		v2[1] = by - goalDot[1];
		
		cp = v1[0] * v2[1] - v1[1] * v2[0];
		
		if(flag == -1)
		{
			if(cp >= 0)
				flag = 1;
			else 
				flag = 0;
		}
		else
		{
			if(flag == 1 && cp < 0)
				return 0;
			else if(flag == 0 && cp >= 0)
				return 0;
		}
	}
	return 1;
}
