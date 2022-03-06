#ifndef KARATSUBA_MULTIPLICATION_H
#define KARATSUBA_MULTIPLICATION_H

#include <string>

class karatsuba_multiplication
{
public:
	karatsuba_multiplication();

	~karatsuba_multiplication();

	std::string multiply(std::string num_x, std::string num_y);

	/**
	 * \brief Test function to generate results to test actual function
	 * Multiply num_x with num_y
	 * \param num_x Input number
	 * \param num_y Input number
	 * \return result = num_x * num_y
	 */
	std::string multiply_test_function(const std::string num_x, const std::string num_y) const;

	std::string subtract(std::string num_x, std::string num_y);

private:
	std::string addition(std::string num_x, std::string num_y);
	size_t pad_to_powers_of_2(std::string& num_x, std::string& num_y) const;

	/**
	 * \brief Splits a number into half, with num_x shorter or equal in size as num_y
	 * \param input Input number
	 * \param num_x Output number (lhs)
	 * \param num_y Output number (rhs)
	 */
	static size_t split_number(const std::string& input, std::string& num_lhs, std::string& num_rhs);

	static std::string pad_zeros(std::string& input, const size_t num_zeros);

	static void remove_zeros_front(std::string& input);
};

#endif