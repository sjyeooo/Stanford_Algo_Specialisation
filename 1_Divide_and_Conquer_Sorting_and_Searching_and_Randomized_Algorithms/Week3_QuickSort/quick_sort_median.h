#ifndef QUICK_SORT_MEDIAN_H
#define QUICK_SORT_MEDIAN_H
#include "quick_sort.h"

//Implements quick sort while using the median of 3 as the pivot point
class quick_sort_median :
	public quick_sort
{
public:
	quick_sort_median() : quick_sort() {}

protected:
	int get_partition_pos(int arr[], const int left, const int right) override;
};

#endif