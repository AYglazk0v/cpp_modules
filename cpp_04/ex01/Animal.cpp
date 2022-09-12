#include "Animal.hpp"

Animal::Animal() : type_("DEFAULT") {
	std::cout << "[ ANIMAL Default ctor ]" << std::endl;
}

Animal::Animal(const Animal& rhs) {
	*this = rhs;
}

Animal::~Animal() {
	std::cout << "[ ANIMAL Destr ]" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
	if (this == &rhs){
		 return *this;
	}
	type_ = rhs.type_;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "ANIMAL SOUUUUUUUUND" << std::endl;
}

const std::string& Animal::getType() const {
	return type_;
}