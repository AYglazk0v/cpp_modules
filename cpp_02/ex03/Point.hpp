#ifndef POINT_HPP

# define POINT_HPP

# include "Fixed.hpp"

class Point {
	
	private:
		Fixed x_;
		Fixed y_;

	public:
	 	Point(void);
		Point(const float, const float);
		Point(const Point&);
		Point &operator=(const Point&);
		~Point();

	public:
		Fixed const getX(void) const;
		Fixed const getY(void) const;
};

bool bsp(const Point, const Point, const Point, const Point);

#endif