#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		PresidentialPardonForm & operator=(const PresidentialPardonForm& rhs);
		virtual ~PresidentialPardonForm();
		virtual void execute(Bureaucrat const& executor) const;
};
#endif