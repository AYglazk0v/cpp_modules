#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form(target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : Form(getTarget(), 145, 137) {
  *this = rhs;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
  Form::operator=(rhs);
  return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	Form::CheckExecution(executor);
  std::string fileName = getTarget() + "_shrubbery";
	std::ofstream ofile(fileName.c_str());
    if (!ofile) {
      throw std::runtime_error("File couldn't be created");
    }
    std::cout << "File with ASCII tree was created!" << std::endl;
	ofile << ASCII_THREE;
    ofile.close();
}