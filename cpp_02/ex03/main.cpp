#include "Point.hpp"

int main(void) {
	Point a;
	Point b(7, 0);
	Point c(0, 5);
	std::cout << "point in triangle: " << std::boolalpha << bsp(a, b, c, Point(2, 2)) <<std::endl;
	std::cout << "point in triangle: " << std::boolalpha << bsp(a, b, c, Point(50, 50)) <<std::endl;
}