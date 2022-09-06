#include <iostream>

int main(void) {
	std::string text = "HI THIS IS BRAIN";
	
	std::string* stringPTR = &text;
	std::string& stringREF = text;

	std::cout << "address text\t\t" << &text << std::endl;
	std::cout << "address stringPTR\t" << &stringPTR << std::endl;
	std::cout << "address stringREF\t" << &stringREF << std::endl;

	std::cout << "value text\t\t" << text << std::endl;
	std::cout << "value stringPTR\t\t" << *stringPTR << std::endl;
	std::cout << "value stringREF\t\t" << stringREF << std::endl;
}