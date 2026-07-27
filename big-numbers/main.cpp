#include "big_numbers.h"

#include <iostream>

int main() {
    auto number1 = BigNumbers("114575");
    auto number2 = BigNumbers("78524");
    auto result = number1 + number2;
    std::cout << result.GetString() << std::endl;

	return 0;
}