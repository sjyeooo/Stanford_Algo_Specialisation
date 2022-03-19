#include "quick_sort.h"

#include <utility>

size_t quick_sort::sort(int arr[], const int left, const int right)
{

	//Base case of recursion
	if (right <= left)
		return 0;

	//Keep track of number of compares
	num_compares_ += (right - left);

	const size_t length = (right - left + 1);
	const int parition_pos = get_partition_pos(arr, left, right);

	const int pos = partition(arr, left, right, parition_pos);
	sort(arr, left, pos - 1);
	sort(arr, pos + 1, right);

	return num_compares_;
}

int quick_sort::partition(int arr[], const int left, const int right, const int parition_pos) const
{
	int i = left + 1;	//[left, i-1] = less than partition val | [i,j-1] = higher than partition val
	int j = left + 1;	//Everything left of j is what we have looked at
	
	//Set partition value to be at 0
	if (parition_pos != left)
		std::swap(arr[left], arr[parition_pos]);

	const int pivot_val = arr[left];

	while (j <= right)
	{
		//new element we are looking at is lower than pivot value
		if (arr[j] < pivot_val)
		{
			std::swap(arr[j], arr[i]);
			i++;
		}
		j++;
	}

	std::swap(arr[left], arr[i-1]);

	return i-1;
}

int quick_sort::get_partition_pos(int arr[], const int left, const int right)
{
	return left;
}