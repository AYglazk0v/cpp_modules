#include "Ice.hpp"

Ice::Ice() {
	type_ = "ice";
}

Ice::~Ice() {
	std::cout << "[ ICE DESTR ]" << std::endl;
}

Ice::Ice(const Ice& rhs) : AMateria() {
	*this = rhs;
}

Ice& Ice::operator=(const Ice& rhs) {
	type_ = rhs.type_;
	return *this;
}

AMateria* Ice::clone() const {
	Ice *copy = new Ice(*this);
	return copy;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}