#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Subarray Info
typedef struct {
	unsigned int left; // Left Index 
	unsigned int right; // Right Index
	long long sum; // Sum of array[left] + ... + array[right]
} SI;

int main()
{
	int n; // How many numbers

	while (scanf("%d", &n) != EOF)
	{
		// Initial
		int segment_min_index = 0, segment_max_index = 0;
		long long temp_sum, raw_data, now_price = 0, segment_min_price = 0, segment_max_price = 0;
		SI best_result;

		best_result.sum = 0x8000000000000000;

		// Input
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &raw_data);

			// Processing
			// Treating raw_data as 'price diff of every day'
			// Computing price of every day.
			// When encounting a new low price, calculating the best profit before the day
	
			now_price += raw_data;

			if (now_price > segment_max_price)
			{
				segment_max_index = i;
				segment_max_price = now_price;
			}

			if (now_price < segment_min_price || i == n - 1)
			{
				if ((temp_sum = segment_max_price - segment_min_price) > best_result.sum)
				{
					best_result.left = segment_min_index;
					best_result.right = segment_max_index;
					best_result.sum = temp_sum;
				}
								
				segment_max_index = segment_min_index = i + 1;
				segment_max_price = segment_min_price = now_price;
			}
		}

		// Output
		printf("%d %d %lld\n", best_result.left, best_result.right, best_result.sum);
	}
}