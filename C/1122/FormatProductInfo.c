#include <stdio.h>

int main()
{
	int no;
	char str[11] = "";
	double price;
	printf("Item No.\tUnit Price\tPurchase Date\n");
	
	while(scanf("%d %lf %s", &no, &price, str) != EOF)
	{
		if(price > 9999.99)
			price = 9999.99;
		printf("%-8d\t$%9.2lf\t%s\n", no, price, str);
	}
	
	return 0;
}
