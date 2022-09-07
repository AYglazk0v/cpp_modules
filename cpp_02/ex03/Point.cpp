#include "Point.hpp"

Point::Point(void) : x_(0), y_(0) {};

Point::Point(const float x, const float y) : x_(x), y_(y) {};

Point::Point(const Point &point) : x_(point.x_), y_(point.y_) {};

Point::~Point() {};

Fixed const Point::getX(void) const {
	return x_;
}

Fixed const Point::getY(void) const {
	return y_;
}

Point& Point::operator=(const Point& rhs) {
	if (this == &rhs) {
		return *this;
	}
	x_ = rhs.getX();
	y_ = rhs.getY();
	return *this;
}
