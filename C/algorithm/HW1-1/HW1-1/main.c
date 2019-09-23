#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Subarray Info
typedef struct {
	unsigned int left; // Left Index 
	unsigned int right; // Right Index
	long long sum; // Sum of array[left] + ... + array[right]
} SI;

SI best_result;
long long *nums; // Storage

// Find-Max-Crossing-Subarray
void FMCS(int low, int high)
{
	// Initialize left_sum and right_sum to a big nagetive number
	long long left_sum = 0x8000000000000000;
	long long right_sum = 0x8000000000000000;
	long long sum = 0;
	unsigned int max_left = 0, max_right = 0;
	unsigned int mid = (low + high) / 2;

	// Finding max-left index
	for (int i = mid; i >= low; --i)
	{
		sum += nums[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	// Finding max-right index
	sum = 0;
	for (int i = mid + 1; i <= high; ++i)
	{
		sum += nums[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}

	// Setting si when find a bigger sum
	if (left_sum + right_sum > best_result.sum)
	{
		best_result.left = max_left;
		best_result.right = max_right;
		best_result.sum = left_sum + right_sum;
	}
}

// Find-Maximum-Subarray
void FMS(unsigned int low, unsigned int high)
{
	// Base case: only one element
	if (low == high)
	{
		// Setting si when find a bigger sum
		if (nums[low] > best_result.sum)
		{
			best_result.left = low;
			best_result.right = high;
			best_result.sum = nums[low];
		}
	}
	else
	{
		unsigned int mid = (low + high) / 2;

		// Finding maximum subarray of left part
		FMS(low, mid);
		// Finding maximum subarray of right part
		FMS(mid + 1, high);
		// Finding maximum subarray crossing left and right parts
		FMCS(low, high);
	}
}

int main()
{
	unsigned int n; // How many numbers

	nums = malloc(sizeof(long long) * 100000);

	while (scanf("%u", &n) != EOF)
	{
		// Initial
		best_result.sum = 0x8000000000000000;

		// Input
		for (unsigned int i = 0; i < n; ++i)
		{
			scanf("%lld", &nums[i]);
		}

		// Processing
		FMS(0, n - 1);

		// Output
		printf("%d %d %lld\n", best_result.left, best_result.right, best_result.sum);
	}

	free(nums);
}