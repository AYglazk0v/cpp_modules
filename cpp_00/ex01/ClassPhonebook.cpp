#include "ClassPhonebook.hpp"

Phonebook::Phonebook() { }

Phonebook::~Phonebook() {
	return ;
}

void Phonebook::toSend(Contact contact, int num){
	contact_[(num - 1) % 8] = contact;
}

void Phonebook::toSearch() {
	std::string	cmd;
	int			num;
	
	while (1) {
		std::cout << "ENTER INDEX OR \"STOP\": ";
		std::cin >> cmd;
		if (cmd == "STOP") {
			break;
		}
		std::istringstream(cmd) >> num;
		if (num < 0) {
			std::cout << "[Error] NOT CORRECTED INDEX" << std::endl;
			continue ;
		} else {
			int i = 0;
			while (i < 8) {
				if (contact_[i].getIndex() == num){
					std::cout<< std::setw(10) << num << "|" << contact_[(num - 1) % 8] << std::endl;
					break;
				}
				i++;
			}
			if (i == 8) {
			std::cout << "[Error] NOT CORRECTED INDEX" << std::endl;
			}
		}
	}
	std::cin.ignore();
}