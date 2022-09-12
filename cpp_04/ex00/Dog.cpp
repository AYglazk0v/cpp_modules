#include "Dog.hpp"

Dog::Dog() {
	type_ = "DOG";
	std::cout << "[ Dog DEFAULT CTOR ]" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal() {
	*this = rhs;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this == &rhs) {
		return *this;
	}
	type_ = rhs.type_;
	return *this;
}

Dog::~Dog() {
	std::cout << "[ DOG DESTR ]" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "HAW" << std::endl;
}