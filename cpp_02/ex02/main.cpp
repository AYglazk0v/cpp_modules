#include "Fixed.hpp"



int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{	
		Fixed a (13.37f);
		Fixed c (a);
		Fixed b (22.06f);
		Fixed d (1.0f);
		Fixed e (2);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
		std::cout << "e = " << e << std::endl;
		std::cout << "a + b = " << a + b << std::endl;
		std::cout << "a - b = " << a - b << std::endl;
		std::cout << "a - c = " << a - c << std::endl;
		std::cout << "d * e = " << d * e << std::endl;
		std::cout << "b / e = " << b / e << std::endl;
		std::cout << a << " > " << b << " : " << std::boolalpha << (a > b) << std::endl;
		std::cout << a << " < " << b << " : " << std::boolalpha << (a < b) << std::endl;
		std::cout << a << " <= " << c << " : " << std::boolalpha << (a <= c) << std::endl;
		std::cout << a << " == " << b << " : " << std::boolalpha << (a == b) << std::endl;
		std::cout << a << " == " << c << " : " << std::boolalpha << (a == c) << std::endl;
		std::cout << a << " != " << e << " : " << std::boolalpha << (a != e) << std::endl;
		std::cout << e << " != " << e << " : " << std::boolalpha << (e != e) << std::endl;
		return 0;
	}
}