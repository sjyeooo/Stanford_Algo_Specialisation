#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

struct jobs_type
{
	jobs_type() = default;
	jobs_type(int32_t weight, int32_t length) : weight(weight), length(length)
	{
	}

	int32_t weight = 0;
	int32_t length = 0;
};

bool comp_algo_1(jobs_type &a, jobs_type &b)
{
	int32_t diff_a = a.weight - a.length;
	int32_t diff_b = b.weight - b.length;
	// Sort with higher (weight-length) in front, with weight as the tie-breaker
	if (diff_a > diff_b || (diff_a == diff_b && a.weight > b.weight))
		return true;
	else
		return false;
}

bool comp_algo_2(jobs_type &a, jobs_type &b)
{
	double ratio_a = static_cast<double>(a.weight) / static_cast<double>(a.length);
	double ratio_b = static_cast<double>(b.weight) / static_cast<double>(b.length);
	// Sort with larger ratio in front
	return (ratio_a > ratio_b);
}

int64_t compute_weighted_result(std::vector<jobs_type> &jobs)
{
	int64_t completion_time{0};
	int64_t result{0};
	for (const auto job : jobs)
	{
		completion_time += job.length;
		result += job.weight * completion_time;
	}

	return result;
}