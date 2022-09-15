#ifndef FORM_HPP

# define FORM_HPP
# include <sstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name_;
		bool is_signed_;
		const int grade_;
		void CheckGradeForException();

	public:
		Form();
		Form(const std::string& name, int grade);
		Form(const Form& rhs);
		Form& operator=(const Form& rhs);
		~Form();

	public:
		bool getSign() const;
		const std::string getName() const;
		int getGrade() const;
		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(const std::string& error);
				const char* what() const throw();
				virtual ~GradeTooHighException() throw();
			private:
				std::string err_;
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