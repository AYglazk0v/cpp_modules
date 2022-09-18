#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "Form.hpp"

#define ASCII_THREE \
"                ccee88oo                    \n"\
"              C8O8O8Q8PoOb o8oo             \n"\
"            dOB69QO8PdUOpugoO9bD            \n"\
"            CgggbU8OU qOp qOdoUOdcb         \n"\
"                6OuU  /p u gcoUodpP         \n"\
"                  \\\\//  /douUP             \n"\
"                    \\\\////                 \n"\
"                    |||/\\                   \n"\
"                    |||\\/                   \n"\
"                    |||||                   \n"\
"              .....//||||\\....              \n"\

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm& rhs);
		virtual ~ShrubberyCreationForm();
		virtual void execute(const Bureaucrat& executor) const;
};

#endif