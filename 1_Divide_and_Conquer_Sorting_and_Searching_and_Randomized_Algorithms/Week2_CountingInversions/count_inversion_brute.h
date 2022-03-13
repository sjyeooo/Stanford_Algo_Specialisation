#ifndef COUNT_INVERSION_BRUTE_H
#define COUNT_INVERSION_BRUTE_H

//Brute force implementation of count inversion
class count_inversion_brute
{
public:
	count_inversion_brute();
	~count_inversion_brute();

	size_t count(int arr[], const size_t length);
};

#endif