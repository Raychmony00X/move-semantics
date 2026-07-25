#include <iostream>
#include <vector>
#include <utility>

void MoveVectors(std::vector<std::string>& one, std::vector<std::string>& two) {
	std::vector<std::string> temp = std::move(one);
	one = std::move(two);
	two = std::move(temp);
}

int main() {
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	MoveVectors(one, two);
	for (size_t i = 0; i < one.size(); ++i) {
		std::cout << one[i];
	}
	std::cout << std::endl;

	for (size_t i = 0; i < two.size(); ++i) {
		std::cout << two[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}