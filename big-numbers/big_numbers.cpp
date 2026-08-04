#include "big_numbers.h"

BigNumbers::BigNumbers(std::string big_numbers) : m_big_numbers(big_numbers){}

BigNumbers::BigNumbers(BigNumbers&& other) noexcept : 
	m_big_numbers(std::exchange(other.m_big_numbers, "")) { }

BigNumbers& BigNumbers::operator=(BigNumbers&& other) noexcept {
	std::swap(m_big_numbers, other.m_big_numbers);
	return *this;
}

BigNumbers BigNumbers::operator+(const BigNumbers& other) const {
	if (m_big_numbers.empty() || other.m_big_numbers.empty()) {
		throw std::runtime_error("String is empty!");
	}

	std::string result;
	int str1_i = m_big_numbers.size() - 1;
	int str2_i = other.m_big_numbers.size() - 1;
	int carry = 0;
	while (str1_i >= 0 || str2_i >= 0 || carry == 1) {
		int digit1 = (str1_i >= 0) ? m_big_numbers[str1_i] - '0' : 0;
		int digit2 = (str2_i >= 0) ? other.m_big_numbers[str2_i] - '0' : 0;
		int sum = digit1 + digit2 + carry;
		carry = (sum >= 10) ? 1 : 0;
		result += (sum % 10) + '0';
		str1_i--;
		str2_i--;
	}

	std::reverse(result.begin(), result.end());
	return result;
}

std::string BigNumbers::MultByDigit(const std::string& num, int digit) const {
	std::string result;
	int carry = 0;
	int i = num.size() - 1;
	while (i >= 0) {
		int current_num = num[i] - '0';
		int result_int = current_num * digit + carry;
		int record = result_int % 10;
		carry = result_int / 10;
		result += (record + '0');
		i--;
	}

	if (carry != 0) result += (carry + '0');
	std::reverse(result.begin(), result.end());
	return result;
}

BigNumbers& BigNumbers::operator*=(const BigNumbers& other){
	if (m_big_numbers.empty() || other.m_big_numbers.empty()) {
		throw std::runtime_error("String is empty!");
	}

	int i = other.m_big_numbers.size() - 1;
	int shift = 0;
	BigNumbers result("0");
	while (i >= 0) {
		int digit = other.m_big_numbers[i] - '0';
		std::string str = MultByDigit(m_big_numbers, digit);
		if (shift >= 1) {
		str += std::string(shift, '0');
		}

		shift++;
		result = result + BigNumbers(str);
		i--;
	}

	m_big_numbers = result.m_big_numbers;
	return *this;
}

std::string BigNumbers::GetString() const {
	return m_big_numbers;
}