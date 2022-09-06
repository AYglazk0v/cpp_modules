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

	public:
		Fixed& operator=(const Fixed& rhs);
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

	public:
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
};

std::ostream& operator<<(std::ostream& output, const Fixed& rhs);

#endif