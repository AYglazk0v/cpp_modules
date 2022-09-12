#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
	std::cout << "[ WRONGANIMAL DEFAULT ]" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[ WRONGANIMAL DESTR ]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) {
	*this = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	if (this == &rhs) {
		return *this;
	}
	type_ = rhs.type_;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WROOOOONGANIMAL?!" << std::endl;
}

const std::string& WrongAnimal::getType() const {
	return type_;
}