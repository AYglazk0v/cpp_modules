#include "Harl.hpp"

namespace {
	int findLevelHarl(const std::string& msg) {
		std::string type_msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		for (int i = -1; i < 4; ++i) {
			if (type_msg[i] == msg) {
				return i;
			}
		}
		return -1;
	}
}

Harl::Harl() {
	message_type_[0] = &Harl::debug;
	message_type_[1] = &Harl::info;
	message_type_[2] = &Harl::warning;
	message_type_[3] = &Harl::error;
}

Harl::~Harl() {};

void Harl::complain(int level){
	for (int i = level; i < 4; ++i) {
		(this->*message_type_[i])();
	}
}

void Harl::filterHarl(const std::string& msg){
	int lvl = findLevelHarl(msg);
	switch (lvl)
	{
	case 0:
		complain(0);
		break;
	case 1:
		complain(1);
		break;
	case 2:
		complain(2);
		break;
	case 3:
		complain(3);
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
				"7XL-double-cheese-triple-pickle-special-ketchup"
				"burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
				"You didn’t put enough bacon in my burger! "
				"If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
				"I’ve been coming for years whereas you started working "
				"here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}