#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm & rhs);
		RobotomyRequestForm & operator=(const RobotomyRequestForm& rhs);
		virtual ~RobotomyRequestForm();
		virtual void execute(const Bureaucrat& executor) const;
};

#endif