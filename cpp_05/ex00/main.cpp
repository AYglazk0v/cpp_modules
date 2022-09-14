#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat first("first", 45);
	Bureaucrat second(first);

	std::cout << first << std::endl;
	std::cout << second << std::endl;
	second = (Bureaucrat("second", 5));
	std::cout << second << std::endl;
	
	std::cout << "-------------" << std::endl;

	try {
		Bureaucrat bur("test1", 150);
		std::cout << bur << std::endl;
		bur.DecrementGrade();
		std::cout << bur << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-------------" << std::endl;

	try {
		Bureaucrat bur("test2", 1);
  		std::cout << bur << std::endl;
		bur.IncrementGrade();
		std::cout << bur << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-------------" << std::endl;
	
	try {
		Bureaucrat bur("test3", -50);
		std::cout << bur << std::endl;
		bur.IncrementGrade();
		std::cout << bur << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-------------" << std::endl;
	
	try {
		Bureaucrat bur("test4", 50);
		std::cout << bur << std::endl;
		bur.DecrementGrade();
		std::cout << bur << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}