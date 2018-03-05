#include <stdio.h>

int main()
{
	int d, m, y;
	while(scanf("%d/%d/%d", &m, &d, &y) != EOF)
	{
		printf("%04d%02d%02d\n", y, m, d);
	}
	return 0;
}