#include <stdio.h>

int main()
{
	int gs1, gi, pc, in, cb;
	while(scanf("%d-%d-%d-%d-%d", &gs1, &gi, &pc, &in, &cb) != EOF)
	{
		printf("GSI prefix: %d\n", gs1);
		printf("Group identifier: %d\n", gi);
		printf("Publisher code: %d\n", pc);
		printf("Item number: %d\n", in);
		printf("Check bit: %d\n", cb);
	}
	return 0;
}
