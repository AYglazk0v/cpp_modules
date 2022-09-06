#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	
	private:
		int fixed_point_;
		static const int bits_ = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed& rhs);
		Fixed& operator=(Fixed const& rhs);

	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& output, const Fixed& rhs);

#endif