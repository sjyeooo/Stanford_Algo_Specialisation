#include "count_inversion.h"

count_inversion::count_inversion()
{

}

count_inversion::~count_inversion()
{

}

size_t count_inversion::count(int a[], const size_t length)
{
	return sort_and_count(a, temp_arr, length);
}

size_t count_inversion::sort_and_count(int a[], int temp[], const size_t length)
{
	//Base case of recursive calls, do nothing and return 0
	if (length == 1)
	{
		return 0;
	}

	const size_t length_b = length / 2;
	const size_t length_c = length - length_b;
	int* b = a;
	int* c = a + length_b;

	const size_t x = sort_and_count(b, temp, length_b);
	const size_t y = sort_and_count(c, temp, length_c);
	const size_t z = merge_and_count(b, c, temp, length_b, length_c);

	return (x + y + z);
}

size_t count_inversion::merge_and_count(int arr_left[], int arr_right[], int arr_temp[],
                                        const size_t length_left, const size_t length_right)
{
	size_t left = 0, right = 0, output = 0;
	size_t inversion_cnt = 0;
	
	//Stop when either left or right array has been traversed through
	while (left < length_left && right < length_right)
	{
		if (arr_left[left] <= arr_right[right])
		{
			arr_temp[output++] = arr_left[left++];
		}
		else //Array on the right is higher, implies inversion spotted
		{
			arr_temp[output++] = arr_right[right++];
			inversion_cnt += (length_left - left);
		}
	}

	//Only have left side array remaining
	while (left < length_left)
	{
		arr_temp[output++] = arr_left[left++];
	}
	//Only have right side array remaining
	while (right < length_right)
	{
		arr_temp[output++] = arr_right[right++];
	}

	//Copy values from temporary to actual array
	for (size_t i = 0; i < (length_left + length_right); i++)
		arr_left[i] = arr_temp[i];

	return inversion_cnt;
}