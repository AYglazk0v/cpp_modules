#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &rhs){
	*this = rhs;
}

Intern& Intern::operator=(const Intern& rhs) {
	if (&rhs == this) {
		return *this;
	}
	(void) rhs;
	return (*this);
}

FormType Intern::FindIndexOfForm(const std::string& form) {
	const std::string forms[3] = {"robotomy request", "shrubbery creation", "presidental pardon"};
	int i = 0;
	for (; i < 3 && form != forms[i]; ++i);
	return static_cast<FormType>(i);
}

Form *Intern::makeForm(const std::string name_form, const std::string target) {
	switch (FindIndexOfForm(name_form))
	{
	case ROBOTOMY:
		std::cout << "Intern creates form \"" << target << "\"" << std::endl;
		return new RobotomyRequestForm(target);
	case SHRUBBERY:
		std::cout << "Intern creates form \"" << target << "\"" << std::endl;
		return new ShrubberyCreationForm(target);
	case PRESIDENTAL:
		std::cout << "Intern creates form \"" << target << "\"" << std::endl;
		return new PresidentialPardonForm(target);	
	default:
		std::cout <<"No such type of form exist!\n\
Please choose from available forms:\n\
	1) robotomy request\n\
	2) shrubbery creation\n\
	3) presidental pardon" << std::endl;
	}
	return NULL;
}