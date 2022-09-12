#include "Cure.hpp"

Cure::Cure() {
	type_ = "cure";
}

Cure::~Cure() {
	std::cout << "[ CURE DESTR " << type_ << " ]" << std::endl;
}

Cure::Cure(const Cure& rhs) : AMateria() {
	*this = rhs;
}

Cure& Cure::operator=(const Cure& rhs) {
	type_ = rhs.type_;
	return *this;
}

AMateria* Cure::clone() const {
	Cure *copy = new Cure(*this);
	return copy;
}

void Cure::use(ICharacter& targer) {
	std::cout << "* heals " << targer.getName() << "'s wounds *" << std::endl;
}