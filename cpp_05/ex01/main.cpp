#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat first("first", 42);
		Bureaucrat second("second", 1);
		Form get_money("get money", 21);
		std::cout << get_money << std::endl;
		second.signForm(get_money);
		std::cout << get_money << std::endl;

		Form to_add_data("to add data", 151);

	}
	catch(const std::exception& e)
	{
			std::cerr << e.what() << '\n';
	}
}