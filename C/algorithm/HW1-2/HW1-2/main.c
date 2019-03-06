#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Subarray Info
typedef struct {
	unsigned int left; // Left Index 
	unsigned int right; // Right Index
	long long sum; // Sum of array[left] + ... + array[right]
} SI;

int main()
{
	int n; // How many numbers
	long long *price_diff = malloc(sizeof(long long) * 100000); // Storaging raw data
	long long *price = malloc(sizeof(long long) * 100001); // price_diff[i] = price[i + 1] - price[i]

	while (scanf("%d", &n) != EOF)
	{
		// Initial
		int segment_min_index, segment_max_index;
		long long temp_sum;
		SI best_result;

		best_result.sum = 0x8000000000000000;

		// Input
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &price_diff[i]);
		}

		// Processing
		// Constructing price[0 ... n + 1]
		// When encounting a new low, calculating the best profit before the new low
		segment_max_index = segment_min_index = 0;
		price[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			price[i] = price_diff[i - 1] + price[i - 1];

			if (price[i] > price[segment_max_index])
			{
				segment_max_index = i;
			}

			if (price[i] < price[segment_min_index] || i == n)
			{
				if ((temp_sum = price[segment_max_index] - price[segment_min_index]) > best_result.sum)
				{
					best_result.left = segment_min_index;
					best_result.right = segment_max_index - 1;
					best_result.sum = temp_sum;
				}

				segment_max_index = segment_min_index = i;
			}
		}
		
		// Output
		printf("%d %d %lld\n", best_result.left, best_result.right, best_result.sum);
	}

	free(price_diff);
	free(price);

	return 0;
}