#include "iter.hpp"

#include <iostream>

template<typename T> void printT(T& x) {
	std::cout << x;
}

int main() {
	int arr[3] = {4, 2, 42};
	iter(arr, 3, printT);

	std::cout << std::endl;

	std::string sarr[3] = {"sarr", " is ", "array string"};
	iter(sarr, 3, printT);

	std::cout << std::endl;
}