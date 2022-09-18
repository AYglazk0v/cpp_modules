#ifndef INTERN_HPP

# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

enum FormType {
  ROBOTOMY,
  SHRUBBERY,
  PRESIDENTAL,
  OTHER
};

class Intern {
	private:
		FormType FindIndexOfForm(const std::string& form);
	
	public:
		Intern();
		~Intern();
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
	
	public:
		Form* makeForm(const std::string name_form, const std::string target_form);
};

#endif