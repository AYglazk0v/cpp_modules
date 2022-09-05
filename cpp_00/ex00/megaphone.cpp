#include <iostream>

namespace {
	inline void printWordToUpper(const std::string& str) {
		for (std::string::const_iterator it = str.begin(), ite = str.end(); it != ite; ++it) {
			std::cout<< static_cast<char>(toupper(*it));
		}
	}
}

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		std::string out;
		for (int i = 1; i < argc; ++i) {
			printWordToUpper(static_cast<std::string>(argv[i]));
		}
		std::cout<<std::endl;
	}
	return 0;
}