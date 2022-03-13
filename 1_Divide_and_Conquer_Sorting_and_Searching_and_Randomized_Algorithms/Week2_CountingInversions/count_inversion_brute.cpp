#include "count_inversion_brute.h"

count_inversion_brute::count_inversion_brute()
{

}

count_inversion_brute::~count_inversion_brute()
{

}

size_t count_inversion_brute::count(int arr[], const size_t length)
{
	size_t inv_count = 0;

	for (int i = 0; i < length - 1; i++)
		for (int j = i + 1; j < length; j++)
			if (arr[i] > arr[j])
				inv_count++;

	return inv_count;
}
