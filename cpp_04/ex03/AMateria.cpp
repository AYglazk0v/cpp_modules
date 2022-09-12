#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const std::string& type) : type_(type) {}

AMateria::~AMateria() {
	std::cout << "[ AMATERIA DESTR ]" << std::endl;
}

AMateria::AMateria(const AMateria& rhs) {
	*this = rhs;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
	if (this == &rhs){
		return *this;
	}
	type_ = rhs.type_;
	return *this;
}

const std::string& AMateria::getType() const {
	return type_;
}