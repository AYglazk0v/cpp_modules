#include <cstdlib>
#include "ClassPhonebook.hpp"
#include "ClassContact.hpp"

namespace {
	void toParsContactFild(std::string &line, int i) {
		if (i == 0) {
			std::cout << "FIRST NAME: ";
		} else if (i == 1) {
			std::cout << "LAST NAME: ";
		} else if (i == 2) {
			std::cout << "NICKNAME: ";
		} else if (i == 3) {
			std::cout << "PHONE NUMBER: ";
		} else if (i == 4) {
			std::cout << "DARKEST SECRET: ";
		}
		do {
			getline(std::cin, line);
			if (!std::cin){
				std::exit(EXIT_FAILURE);
			}
			if (line.length() == 0) {
				std::cout << "INCORRECT VALUE" << std::endl;
			}
		} while (line.length() == 0);
	}

	void toAdd(std::string &line, int &num, Phonebook &pb) {
		std::string inform[5];

		for (int i; i < 5; i++) {
			toParsContactFild(line, i);
			if (line.length() > 10) {
				line = line.substr(0,9);
				line.replace(9, 9, ".");
			}
			if (line != "ADD" && line != "EXIT" && line != "SEARCH") {
				inform[i] = line;
			} else {
				while (i != 0)
					inform[i--] = "";
				return ;
			}
		}
		num++;
		pb.toSend(Contact(inform[0], inform[1], inform[2], inform[3], inform[4], num), num);
	}

	void printHead(){
		std::cout<<"#############################################"<<std::endl;
		std::cout<<"##    ADD    ###    SEARCH    ###   EXIT   ##"<<std::endl;
		std::cout<<"#############################################"<<std::endl;
	}
}

int	main(void) {
	Phonebook pb;
	std::string line;
	int num = 0;
	std::cout << "\x1B[2J\x1B[H";
	while(1){
		printHead();
		std::cout << "CMD --> ";
		getline(std::cin, line);
		if (!std::cin){
			std::exit(EXIT_FAILURE);
		}
		if (line == "ADD") {
			toAdd(line, num, pb);
		}
		else if (line == "SEARCH") {
			pb.toSearch();
		}
		else if (line == "EXIT") {
			break;
		}
			std::cout << "\x1B[2J\x1B[H";
	}
	return 0;
}