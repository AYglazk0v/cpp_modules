#ifndef CLASS_CONTACT_HPP
#define CLASS_CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>

class Contact
{
	private:
		std::string	firstname_;
		std::string	lastname_;
		std::string	nickname_;
		std::string	number_;
		std::string	secret_;
		int			index_;

	public:
		Contact();
		Contact(const std::string &name_, const std::string &lastname_,
				const std::string &niclname_, const std::string &number_, 
				const std::string &secret_, const int &index_);
		~Contact();

		const std::string&	getName() const;
		const std::string&	getLastname() const;
		const std::string&	getNickname() const;
		const std::string&	getNumber() const;
		const std::string&	getSecret() const;
		const int&	getIndex() const;

};

	inline std::ostream& operator <<(std::ostream &os, const Contact &c) {
		return os << std::setw(10)<< c.getName() << "|"
			<< std::setw(10) << c.getLastname() << "|"
			<< std::setw(10) << c.getNickname() << "|"
			<< std::endl;
	}

#endif