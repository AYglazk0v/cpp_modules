#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type_ = "Wrongcat";
	std::cout << "[ WRONGCAT DEFAULT CTOR ]" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "[ WrongCat DESTR ]" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal() {
	*this = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	if (this == &rhs) {
		return *this;
	}
	type_ = rhs.type_;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WRONG MAUUUUUU" << std::endl;
}