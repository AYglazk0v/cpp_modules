#include "easyfind.hpp"
#include <vector>
#include <set>

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	try {
		std::cout << easyfind(vec, 4) << std::endl;
		std::cout << easyfind(vec, 10) << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what();
	}

	std::cout << std::endl;

	std::set<int> set;
	for (int i = 0; i < 10; i++) {
		set.insert(i);
	}
	try {
		std::cout << easyfind(set, 5) << std::endl;
		std::cout << easyfind(set, 10) << std::endl;
	} catch (std::exception &ex) {
		std::cout << ex.what();
	}
}