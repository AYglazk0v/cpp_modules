#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		Form* robotmy;
		robotmy = intern.makeForm("robotomy request", "robotmy");
		Form* president;
		president = intern.makeForm("presidental pardon", "pr");
		Form *shrubbery;
		shrubbery = intern.makeForm("shrubbery creation", "sh");
		Form* wrong_f;
		wrong_f = intern.makeForm("qwertyuiop", "zxcvbnm");
		delete robotmy;
		delete president;
		delete shrubbery;
		delete wrong_f;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}