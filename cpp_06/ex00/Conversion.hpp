#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <cerrno>
# include <cstdlib>

class Conversion {
	
	private:
		std::string data_;
		char letter_;
		int int_num_;
		float float_num_;
		double double_num_;
		void FindActualTypeOfData();

	private:
		void ConvertChar();
		void ConvertSpecial();
		void ConvertInt();
		void ConvertFloat();
		void ConvertDouble();
		int CheckForInt();
		int CheckForFloat();
		int CheckForSpecial();
		int CheckForDouble();

	public:
		Conversion(const std::string& date);
		Conversion(const Conversion& rhs);
		Conversion& operator=(const Conversion& rhs);
		~Conversion();
		void ConvertData();
};

#endif

