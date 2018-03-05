#include <stdio.h>

void padovan(int, int, int, int, int);

int main()
{
	int mount;
	while(scanf(" %d", &mount) != EOF)
	{
		if(mount <= 2 || mount >= 31)
		{
			printf("2<N<31\n");	
			continue;
		}
		padovan(mount + 1, 0, 0, 1, 1);
		printf("\n");
	}
	return 0;
}

void padovan(int maxLayer, int nowLayer, int n0, int n1, int n2)
{
	if(nowLayer == maxLayer)
		return;
	if(nowLayer == 0)
		printf("%d", n1);
	else
		printf(" %d", n1);
	padovan(maxLayer, nowLayer + 1, n1, n2, n0 + n1);
}
