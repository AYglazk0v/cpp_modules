#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed {
	
	private:
		int fixed_point_;
		static const int bits_ = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& rhs);
		Fixed& operator=(Fixed const& rhs);

	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif