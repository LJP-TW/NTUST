#include <stdio.h>
#include <stdlib.h>

void quickSort(int *, int, int);
int quickSort_getMiddle(int *, int, int);

int main()
{
	int mount;
	while(scanf(" %d", &mount) != EOF)
	{
		int *nums = malloc(mount * sizeof(int));
		for(int i = 0; i < mount; i++)
		{
			scanf(" %d", (nums + i));
		}

		/* debug */
		/*
		for(int i = 0; i < mount; i++)
		{
			if(i == 0)
				printf("%d", *(nums + i));
			else
				printf(" %d", *(nums + i));
		}
		printf("\n");
		*/

		quickSort(nums, 0, mount - 1);

		for(int i = 0; i < mount; i++)
		{
			if(i == 0)
				printf("%d", *(nums + i));
			else
				printf(" %d", *(nums + i));
		}
		printf("\n");

		free(nums);
	}
	return 0;
}

void quickSort(int *nums, int low, int high)
{
	int middle = quickSort_getMiddle(nums, low, high);
	if(middle - 1 >= low)
		quickSort(nums, low, middle - 1);
	if(middle + 1 <= high)
		quickSort(nums, middle + 1, high);	
}

int quickSort_getMiddle(int *nums, int low, int high)
{
	int temp = *(nums + low);
	int direction = 1;
	// 1 : from high to low
	// 0 : from low to high
	
	while(low != high)
	{
		if(direction)
		{
			if(temp < *(nums + high))
			{
				*(nums + low) = *(nums + high);
				++low;
				direction ^= 1;
			}
			else
				--high;
		}
		else
		{
			if(temp > *(nums + low))
			{
				*(nums + high) = *(nums + low);
				--high;
				direction ^= 1;
			}
			else
			{
				++low;
			}
		}
	}
	// low and high point to same index, which represent middle index
	// middle == low && middle == high
	*(nums + low) = temp;
	return low;
}
