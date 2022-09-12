#include "Cat.hpp"

Cat::Cat() {
	type_ = "CAT";
	std::cout << "[ CAT Default ctor ]" << std::endl;
}

Cat::~Cat() {
	std::cout << "[ CAT Destr ]" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal() {
	*this = rhs;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this == &rhs) {
		return *this;
	}
	type_ = rhs.type_;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MAAAAU" << std::endl;
}