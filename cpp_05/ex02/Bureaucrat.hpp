#ifndef BUREAUCRAT_HPP

# define  BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;
class Bureaucrat {
	private:
		const std::string name_;
		int grade_;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

	public:
		const std::string GetName() const;
		int GetGrade() const;
		void IncrementGrade();
		void DecrementGrade();

	class GradeTooHighException : public std::exception {
		private:
			std::string err_;
		public:
			const char* what() const throw();
			GradeTooHighException(const std::string& error);
			virtual ~GradeTooHighException() throw(){};
	};
	
	class GradeTooLowException : public std::exception {
		private:
			std::string err_;
		public:
			const char* what() const throw();
			GradeTooLowException(const std::string& error);
			virtual ~GradeTooLowException() throw() {};
	};

	public:
		void signForm(Form& form);
		void executeForm(const Form& form);
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& b);

#endif
