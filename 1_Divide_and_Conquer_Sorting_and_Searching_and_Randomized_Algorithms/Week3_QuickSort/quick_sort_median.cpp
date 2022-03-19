#include "quick_sort_median.h"

int quick_sort_median::get_partition_pos(int arr[], const int left, const int right)
{
	const int mid = (right + left) / 2;

	const auto left_val = arr[left];
	const auto mid_val = arr[mid];
	const auto right_val = arr[right];

	// Checking for b
	if ((left_val <= mid_val && mid_val <= right_val) || (right_val <= mid_val && mid_val <= left_val))
	{
		return mid;
	}
	// Checking for a
	else if ((mid_val < left_val && left_val < right_val) || (right_val < left_val && left_val < mid_val))
	{
		return left;
	}
	else
	{
		return right;
	}
}
