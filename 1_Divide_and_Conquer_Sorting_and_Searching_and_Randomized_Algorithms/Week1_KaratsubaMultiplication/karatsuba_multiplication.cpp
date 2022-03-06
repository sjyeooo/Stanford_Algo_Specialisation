#include "karatsuba_multiplication.h"

#include <iostream>

karatsuba_multiplication::karatsuba_multiplication()
{

}

karatsuba_multiplication::~karatsuba_multiplication()
{

}

std::string karatsuba_multiplication::multiply(std::string num_x, std::string num_y)
{
	std::string result;
	pad_to_powers_of_2(num_x, num_y);

	//Base case for recursion - single digit multiplication
	if ((num_x.length() == 1) && num_y.length() == 1)
	{
		const int result_integer = atoi(num_x.c_str()) * atoi(num_y.c_str());
		result = std::to_string(result_integer);

		return result;
	}

	//Split number into half
	std::string x0, x1;
	split_number(num_x, x0, x1);
	std::string y0, y1;
	const size_t pow_base_10 = split_number(num_y, y0, y1);

	std::string z0 = multiply(x1, y1);
	std::string z1 = multiply(addition(x0, x1), addition(y0, y1));
	std::string z2 = multiply(x0, y0);

	//(z1 - z2 - z0)
	std::string z1_z2_z0 = subtract(z1, addition(z2, z0));

	result = addition(pad_zeros(z1_z2_z0, pow_base_10), z0);
	result = addition(pad_zeros(z2, pow_base_10 * 2), result);

	remove_zeros_front(result);

	return result;
}

std::string karatsuba_multiplication::multiply_test_function(const std::string num_x, const std::string num_y) const
{
	std::cout << "Running multiply_test_function" << std::endl;

	const unsigned int i_num1 = atoi(num_x.c_str());
	const unsigned int i_num2 = atoi(num_y.c_str());

	const unsigned long long result = static_cast<unsigned long long>(i_num1) *
		static_cast<unsigned long long>(i_num2);
	std::string result_string = std::to_string(result);

	return result_string;
}

std::string karatsuba_multiplication::subtract(std::string num_x, std::string num_y)
{
	std::string result;
	char carry = 0;
	const size_t len_size_x = num_x.length();
	const size_t len_size_y = num_y.length();
	const size_t len_size = std::max(len_size_x, len_size_y);

	std::reverse(num_x.begin(), num_x.end());
	std::reverse(num_y.begin(), num_y.end());

	for (size_t i = 0; i < len_size; i++)
	{
		char num_x_val = 0, num_y_val = 0;
		if (i < len_size_x) num_x_val = num_x.at(i) - '0';
		if (i < len_size_y) num_y_val = num_y.at(i) - '0';
		char diff = num_x_val - num_y_val + carry;
		if (diff < 0)
		{
			if ((i + 1) < len_size_x)//Ensure that num_x still has additional element to deduct since this "10" is from the next element
			{
				diff += 10;
				carry = -1;
			}
			else
			{
				carry = 0;
			}
			result.push_back(std::abs(diff) + '0');
		}
		else //diff >= 0
		{

			result.push_back(diff + '0');
			carry = 0;
		}
	}
	if (carry == -1)
	{
		result.push_back('-');
	}

	std::reverse(result.begin(), result.end());

	remove_zeros_front(result);

	return result;
}

std::string karatsuba_multiplication::addition(std::string num_x, std::string num_y)
{
	std::string result;
	char carry = 0;
	const size_t len_size_x = num_x.length();
	const size_t len_size_y = num_y.length();
	const size_t len_size = std::max(len_size_x, len_size_y);

	std::reverse(num_x.begin(), num_x.end());
	std::reverse(num_y.begin(), num_y.end());

	for (size_t i = 0; i < len_size; i++)
	{
		char num_x_val = 0, num_y_val = 0;
		if (i < len_size_x) num_x_val = num_x.at(i) - '0';
		if (i < len_size_y) num_y_val = num_y.at(i) - '0';
		const char sum = num_x_val + num_y_val + carry;
		const char val = sum % 10;
		carry = sum / 10;
		result.push_back(val + '0');
	}
	// If there is carry existing:
	if (carry)
	{
		result.push_back(carry + '0');
	}

	std::reverse(result.begin(), result.end());

	return result;
}

size_t karatsuba_multiplication::pad_to_powers_of_2(std::string& num_x, std::string& num_y) const
{
	const size_t length_of_string = std::max(num_x.length(), num_y.length());
	size_t length_of_string_pow_2 = 1;
	while (length_of_string_pow_2 < length_of_string)
	{
		length_of_string_pow_2 *= 2;
	}

	while (num_x.length() < length_of_string_pow_2)
		num_x.insert(0, "0");
	while (num_y.length() < length_of_string_pow_2)
		num_y.insert(0, "0");

	return length_of_string;
}

size_t karatsuba_multiplication::split_number(const std::string& input, std::string& num_lhs, std::string& num_rhs)
{
	const std::size_t split_location = input.length() / 2;

	num_lhs = input.substr(0, split_location);
	num_rhs = input.substr(split_location);

	return split_location;
}

std::string karatsuba_multiplication::pad_zeros(std::string& input, const size_t num_zeros)
{
	const std::string padded_zeros(num_zeros, '0');

	return (input + padded_zeros);
}

void karatsuba_multiplication::remove_zeros_front(std::string& input)
{
	//Remove zeros in front
	while (input.length() > 1 && input.at(0) == '0')
		input.erase(0, 1);

}