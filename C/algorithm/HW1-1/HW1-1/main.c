#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Subarray Info
typedef struct {
	unsigned int left; // Left Index 
	unsigned int right; // Right Index
	long long sum; // Sum of array[left] + ... + array[right]
} SI;

// Find-Max-Crossing-Subarray
void FMCS(long long nums[], int low, int mid, int high, SI *si)
{
	// Initialize left_sum and right_sum to a big nagetive number
	long long left_sum = 0x8000000000000000;
	long long right_sum = 0x8000000000000000;
	int max_left, max_right;
	long long sum;

	// Finding max-left index
	sum = 0;
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

	// Setting si
	si->left = max_left;
	si->right = max_right;
	si->sum = left_sum + right_sum;
}

// Find-Maximum-Subarray
void FMS(long long nums[], int low, int high, SI *si)
{
	// Base case: only one element
	if (low == high)
	{
		si->left = low;
		si->right = high;
		si->sum = nums[low];
	}
	else
	{
		SI left_si, right_si, cross_si;
		int mid = (low + high) / 2;

		// Finding maximum subarray of left part
		FMS(nums, low, mid, &left_si);
		// Finding maximum subarray of right part
		FMS(nums, mid + 1, high, &right_si);
		// Finding maximum subarray crossing left and right parts
		FMCS(nums, low, mid, high, &cross_si);

		// Setting si which has biggest sum to si
		if (left_si.sum >= right_si.sum && left_si.sum >= cross_si.sum)
		{
			*si = left_si;
		}
		else if (right_si.sum >= left_si.sum && right_si.sum >= cross_si.sum)
		{
			*si = right_si;
		}
		else
		{
			*si = cross_si;
		}
	}
}

int main()
{
	int n; // How many numbers
	long long nums[100000]; // Storage

	while (scanf("%d", &n) != EOF)
	{
		SI result_si;

		// Input
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &nums[i]);
		}

		// Processing
		FMS(nums, 0, n - 1, &result_si);

		// Output
		printf("%d %d %lld\n", result_si.left, result_si.right, result_si.sum);
	}

	return 0;
}