#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0) {};

Fixed::Fixed(const int num) : fixed_point_(num << bits_) {};

Fixed::Fixed(const float num) : fixed_point_(static_cast<int>(roundf(num * (1 << bits_)))) {};

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& rhs) : fixed_point_(rhs.fixed_point_) {}

Fixed& Fixed::operator=(const Fixed& rhs) {
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

bool Fixed::operator>(const Fixed& rhs) const {
	return fixed_point_ > rhs.fixed_point_;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return fixed_point_ < rhs.fixed_point_; 
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return fixed_point_ <= rhs.fixed_point_;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return fixed_point_ >= rhs.fixed_point_;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return fixed_point_ == rhs.fixed_point_;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return fixed_point_ != rhs.fixed_point_;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed tmp(*this);
	tmp.setRawBits(fixed_point_ + rhs.fixed_point_);
	return tmp;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed tmp(*this);
	tmp.setRawBits(fixed_point_ - rhs.fixed_point_);
	return tmp;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed tmp(*this);
	tmp.setRawBits((fixed_point_ * rhs.fixed_point_) >> bits_);
	return tmp;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed tmp(*this);
	tmp.setRawBits((fixed_point_ << bits_) / rhs.fixed_point_);
	return tmp;
}

Fixed& Fixed::operator++(void) {
	fixed_point_++;
	return *this;
}

Fixed& Fixed::operator--(void) {
	fixed_point_--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	if (lhs > rhs) {
		return rhs;
	} 
	return lhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	return rhs;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
	if (lhs > rhs) {
		return rhs;
	}
	return lhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	return rhs;
}