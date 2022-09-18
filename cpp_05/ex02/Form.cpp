#include "Form.hpp"

Form::Form(): name_("Default"), is_signed_(false), grade_to_sign_(1), grade_to_exec_(1) {
	std::cout << "[Default ctor]" <<  std::endl;
}

Form::Form(const std::string& name, const int grade_to_sign, const int grade_to_exec) : name_(name), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_exec_(grade_to_exec) {
}

Form::~Form() {}

Form::Form(const Form& rhs) : name_(rhs.name_), grade_to_sign_(rhs.grade_to_sign_), grade_to_exec_(rhs.grade_to_exec_) { 
	*this = rhs;
}

Form& Form::operator=(const Form& rhs) {
	if (this == &rhs) {
		return *this;
	}
	is_signed_ = rhs.is_signed_;
	return *this;
}

const std::string Form::getTarget() const {
	return name_;
}

int Form::getGradeToSign() const {
	return grade_to_sign_;
}

int Form::getGradeToExecute() const {
	return grade_to_exec_;
}

bool Form::getSign() const {
	return is_signed_;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.GetGrade() > grade_to_sign_) {
		std::stringstream ss;
		ss << "Form couldn't be signed, bureaucrat grade is "
		<< b.GetGrade() << " but requested grade is " << grade_to_sign_;
		throw GradeTooLowException(ss.str());
	} else {
		is_signed_ = true;
	}
}

void Form::CheckExecution(Bureaucrat const & executor) const {
	if (!is_signed_) {
		throw FormNotSigned();
	} else if (executor.GetGrade() > grade_to_sign_) {
		std::stringstream ss;
		ss << executor.GetName() << " couldn't execute form \"" << name_ << "\" , his grade is too low! Executor grade - " 
		<< executor.GetName() << " Requested grade - " << grade_to_exec_; 
		throw GradeTooLowException(ss.str());
	}
}

const char * Form::FormNotSigned::what() const throw() {
	return ("Form isn't signed");
}

Form::FormNotSigned::~FormNotSigned() throw() { }

Form::GradeTooHighException::GradeTooHighException(const std::string& error) : err_(error) {}

const char* Form::GradeTooHighException::what() const throw() {
	return err_.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::GradeTooLowException(const std::string& error) : err_(error) {}

const char* Form::GradeTooLowException::what() const throw() {
	return err_.c_str();
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

std::ostream& operator<<(std::ostream& output, const Form& f) {
	output << "Form is named: \"" << f.getTarget() 
	<< "\" it could be signed by Bureaucrats with grade: "
	<< f.getGradeToSign() << std::endl
	<< "Now it ";
	if (f.getSign()) {
		output << "signed";
	} else {
		output << "isn't signed";
	}
	return output;
}
