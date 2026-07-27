#include "big_numbers.h"

BigNumbers::BigNumbers(std::string big_numbers) : m_big_numbers(big_numbers){}

BigNumbers::BigNumbers(BigNumbers&& other) noexcept : 
	m_big_numbers(std::exchange(other.m_big_numbers, "")) { }

BigNumbers& BigNumbers::operator=(BigNumbers&& other) noexcept {
	std::swap(m_big_numbers, other.m_big_numbers);
	return *this;
}

BigNumbers BigNumbers::operator+(const BigNumbers& other) const {
	int num1 = std::stoi(m_big_numbers);
	int num2 = std::stoi(other.m_big_numbers);
	int result = num1 + num2;
	return std::to_string(result);
}

BigNumbers BigNumbers::operator*=(const BigNumbers& other) const {
	int num1 = std::stoi(m_big_numbers);
	int num2 = std::stoi(other.m_big_numbers);
	num1 *= num2;
	return std::to_string(num1);
}

std::string BigNumbers::GetString() const {
	return m_big_numbers;
}