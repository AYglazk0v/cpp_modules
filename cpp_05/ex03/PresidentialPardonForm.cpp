#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form(target, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : Form(getTarget(), 25, 5) {
	*this = rhs;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this == &rhs){
		return *this;
	}
	Form::operator=(rhs);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	Form::CheckExecution(executor);
	std::cout<< executor.GetName()
	<< " was paroned bz Zaphod Beeblebrox" << std::endl;
}