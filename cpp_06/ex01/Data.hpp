#ifndef DATA_HPP

# define DATA_HPP
# include <iostream>
# include <stdint.h>

struct Data {
	int	int_;
	char char_;
	std::string str_;
};

std::ostream& operator<<(std::ostream& out, Data& data) {
	return out << "int: " << data.int_ << std::endl
	<< "char: " << data.char_ << std::endl
	<< "sting: " << data.str_ << std::endl;
}

#endif
