#ifndef CLASS_PHONEBOOK_HPP
#define CLASS_PHONEBOOK_HPP

# include <iostream>
# include <string>

# include "ClassContact.hpp"

class Phonebook{
	private:
		Contact contact_[8];

	public:
		Phonebook();
		~Phonebook();
		void toSend(Contact contact, int num);
		void toSearch();
};

#endif