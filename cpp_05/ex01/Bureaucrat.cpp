#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("DEFAULT"), grade_(1) {
	std::cout << "[Default ctor]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade) {
	std::cout << "[Dirent ctor]" << std::endl;
	if (grade_ > 150) {
		throw GradeTooLowException(name_);
	} else if (grade_ < 1) {
		throw GradeTooHighException(name_);
	}
}

void Bureaucrat::signForm(Form& form) {
	if (grade_ > form.getGrade()) {
		std::cout << "Bureaucrat couldn't sign " << form.getName()
		<< "his grade is " << grade_ << " but requested grade is " 
		<< form.getGrade() << std::endl;
	} else {
		form.beSigned(*this);
		std::cout << "Bureaucrat " << name_
		<< " signed form \"" << form.getName() << "\"" << std::endl;
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Destr]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name_(rhs.name_), grade_(rhs.grade_) {
	*this = rhs;
}

const std::string Bureaucrat::GetName() const {
	return name_;
}

int Bureaucrat::GetGrade() const {
	return grade_;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this == &rhs){
		return *this;
	}
	grade_ = rhs.grade_;
	return *this;
}

void Bureaucrat::IncrementGrade() {
	--grade_;
	std::cout << "[INCR] after the increment " + name_ + " it has " << grade_ << std::endl;
	if (grade_ < 1) {
		throw GradeTooHighException(name_);
	}
}

void Bureaucrat::DecrementGrade() {
	++grade_;
	std::cout << "[DECR] after the decrement " + name_ + " it has " << grade_ << std::endl;
	if (grade_ > 150) {
		throw GradeTooLowException(name_);
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name) {
	err_ += name + " bad grade [HighExeption]";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name) {
	err_ += name + " bad grade [LowException]";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return err_.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return err_.c_str();
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& b) {
	return output<< "Bureaucrat " << b.GetName() << " has grade " << b.GetGrade() << std::endl; 
}