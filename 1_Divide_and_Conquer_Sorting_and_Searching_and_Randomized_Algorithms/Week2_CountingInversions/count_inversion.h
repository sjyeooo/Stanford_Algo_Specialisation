#ifndef COUNT_INVERSION_H
#define COUNT_INVERSION_H

constexpr size_t MAX_INV_ARRAY_SIZE = 100000;

class count_inversion
{
public:
	count_inversion();
	~count_inversion();
	size_t count(int a[], const size_t length);
private:
	size_t sort_and_count(int a[], int temp[], const size_t length);

	size_t merge_and_count(int arr_left[], int arr_right[], int arr_temp[],
		size_t length_left, size_t length_right);

	int temp_arr[MAX_INV_ARRAY_SIZE];
};

#endif