#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void (Harl::*message_type_[4])(void);

	public:
		Harl();
		~Harl();
		void complain(int level);
		void filterHarl(const std::string& msg);
};

#endif