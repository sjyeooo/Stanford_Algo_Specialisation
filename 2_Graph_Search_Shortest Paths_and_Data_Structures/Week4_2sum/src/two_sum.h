#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <ctime>
#include <memory>
#include <unordered_set>
#include <vector>

class two_sum
{
  public:
	two_sum() = default;
	~two_sum() = default;

	void insert(std::vector<int64_t> &numbers);
	void insert(const int64_t number);

	auto run(std::vector<int64_t> &targets) -> std::size_t;

	auto run(int64_t target) -> bool;

  private:
	std::unordered_multiset<int64_t> data;
};

#endif