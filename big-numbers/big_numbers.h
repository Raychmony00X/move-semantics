#pragma once

#include <iostream>
#include <string>

class BigNumbers {
public:
	BigNumbers(std::string big_numbers = "");

	BigNumbers(BigNumbers&& other) noexcept;

	BigNumbers& operator=(BigNumbers&& other) noexcept;

	BigNumbers operator+(const BigNumbers& other) const;

	BigNumbers& operator*=(const BigNumbers& other);

	std::string GetString() const;

private:
	std::string m_big_numbers;

	std::string MultByDigit(const std::string& num, int digit) const;

};