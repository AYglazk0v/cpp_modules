#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int num) : fixed_point_(num << bits_) {
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float num) : fixed_point_(static_cast<int>(roundf(num * (1 << bits_)))) {
	std::cout << "Float constructor called" << std::endl;
};

Fixed::~Fixed() {
	std::cout << "Destructor calledDestr called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs) {
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs){
		return *this;
	}
	fixed_point_ = rhs.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& output, const Fixed& rhs) {
	return output << rhs.toFloat();
}

int Fixed::toInt() const {
	return static_cast<int>(fixed_point_ >> bits_);
}

float Fixed::toFloat() const {
	return (static_cast<float>(fixed_point_) / (1 << bits_));
}

int Fixed::getRawBits(void) const {
	return fixed_point_;
}

void Fixed::setRawBits(int const raw) {
	fixed_point_ = raw;
}