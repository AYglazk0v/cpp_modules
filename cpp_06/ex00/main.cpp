#include "Conversion.hpp"

int main(int argc, char **argv) {
	if (argc == 2) {
		try {
			Conversion conv(static_cast<std::string>(argv[1]));
			conv.ConvertData();
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	} else {
		std::cerr << "argc != 2" << std::endl;
		exit(EXIT_FAILURE);
  }
}