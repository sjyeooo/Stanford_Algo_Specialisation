#include "two_sum.h"

#include <iostream>

void two_sum::insert(std::vector<int64_t> &numbers)
{
	for (const auto number : numbers)
	{
		data.insert(number);
	}
}
void two_sum::insert(const int64_t number)
{
	data.insert(number);
}

auto two_sum::run(std::vector<int64_t> &targets) -> std::size_t
{
	std::size_t count{0};
	for (const auto target : targets)
	{
		for (const auto element : data)
		{
			const auto key = target - element;
			std::size_t threshold{0};
			if (key == element)
			{
				threshold = 1;
			}
			if (data.count(key) > threshold)
			{
				count++;
				break;
			}
		}
	}

	return count;
}