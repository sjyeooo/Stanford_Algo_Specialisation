#ifndef QUICK_SORT_FINAL_H
#define QUICK_SORT_FINAL_H

#include "quick_sort.h"

//Implements quick sort while using the final element as the pivot point
class quick_sort_final :
	public quick_sort
{
public:
	quick_sort_final() : quick_sort() {}

protected:
	int get_partition_pos(int arr[], const int left, const int right) override
	{
		return right;
	}
};

#endif