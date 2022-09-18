#ifndef FORM_HPP

# define FORM_HPP
# include <sstream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		const std::string name_;
		bool is_signed_;
		const int grade_to_sign_;
		const int grade_to_exec_;
		void CheckGradeForException();

	public:
		Form();
		Form(const std::string& name, const int grade_to_sign, const int grade_to_exec);
		Form(const Form& rhs);
		Form& operator=(const Form& rhs);
		virtual ~Form();

	public:
		bool getSign() const;
		const std::string getTarget() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& b);

	public:
		virtual void execute(const Bureaucrat& executor) const = 0;
		void CheckExecution(const Bureaucrat& executor) const;

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(const std::string& error);
				const char* what() const throw();
				virtual ~GradeTooHighException() throw();
			private:
				std::string err_;
		};

		class FormNotSigned: public std::exception {
			public:
				const char* what() const throw();
				virtual ~FormNotSigned() throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				GradeTooLowException(const std::string& error);
				const char* what() const throw();
				virtual ~GradeTooLowException() throw();
			private:
				std::string err_;
		};
};

std::ostream& operator<<(std::ostream& output, const Form& f);

#endif
