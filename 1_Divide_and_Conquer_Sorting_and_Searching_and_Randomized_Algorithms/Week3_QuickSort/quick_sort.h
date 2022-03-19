#ifndef QUICK_SORT_H
#define QUICK_SORT_H

constexpr size_t MAX_QS_ARRAY_SIZE = 10000;

//Implements quick sort while using the first element as the pivot point
class quick_sort
{
public:
	quick_sort() = default;
	~quick_sort() = default;

	size_t sort(int arr[], const int left, const int right);

	size_t get_number_compares() {
		return num_compares_;
	}

protected:
	virtual int get_partition_pos(int arr[], const int left, const int right);
	size_t num_compares_ = 0;

	int partition(int arr[], const int left, const int right, const int parition_pos) const;

};

#endif