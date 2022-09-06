#include "Harl.hpp"

Harl::Harl() {
	message_type_[0] = &Harl::debug;
	message_type_[1] = &Harl::info;
	message_type_[2] = &Harl::warning;
	message_type_[3] = &Harl::error;
}

Harl::~Harl() {};

void Harl::complain(std::string level) {
	std::string type_msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = -1; i < 4; ++i) {
		if (level == type_msg[i]){
			(this->*message_type_[i])();
			return ;
		}
	}
	std::cerr << "Error: comlaint " << level << " not found!" << std::endl;
	exit(1);
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my "
				"7XL-double-cheese-triple-pickle-special-ketchup"
				"burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. "
				"You didn’t put enough bacon in my burger! "
				"If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. "
				"I’ve been coming for years whereas you started working "
				"here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}