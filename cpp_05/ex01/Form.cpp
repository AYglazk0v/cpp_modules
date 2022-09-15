#include "Form.hpp"

Form::Form(): name_("Default"), is_signed_(false), grade_(1) {
	std::cout << "[Default ctor]" <<  std::endl;
}

Form::Form(const std::string& name, int grade) : name_(name), is_signed_(false), grade_(grade) {
	if (grade_ > 150) {
		std::stringstream ss;
		ss << "Grade should be from 1 to , but your grade is " << grade_;
		throw GradeTooLowException(ss.str());
	} else if (grade_ < 1) {
		std::stringstream ss;
		ss << "Grade should be from 1 to , but your grade is " << grade_;
		throw GradeTooHighException(ss.str());
	}
}

Form::~Form() {}

Form::Form(const Form& rhs) : name_(rhs.name_), grade_(rhs.grade_) {
	*this = rhs;
}

Form& Form::operator=(const Form& rhs) {
	if (this == &rhs) {
		return *this;
	}
	is_signed_ = rhs.is_signed_;
	return *this;
}

const std::string Form::getName() const {
	return name_;
}

int Form::getGrade() const {
	return grade_;
}

bool Form::getSign() const {
	return is_signed_;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.GetGrade() > grade_) {
		std::stringstream ss;
		ss << "Form couldn't be signed, bureaucrat grade is "
		<< b.GetGrade() << " but requested grade is " << grade_;
		throw GradeTooLowException(ss.str());
	} else {
		is_signed_ = true;
	}
}

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
	output << "Form is named: \"" << f.getName() 
	<< "\" it could be signed by Bureaucrats with grade: "
	<< f.getGrade() << std::endl
	<< "Now it ";
	if (f.getSign()) {
		output << "signed";
	} else {
		output << "isn't signed";
	}
	return output;
}