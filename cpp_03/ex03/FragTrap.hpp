#ifndef FRAGTRAP_HPP

# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:
		void SetDefaultPoints();

	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& rhs);
		FragTrap& operator=(const FragTrap& rhs);
		virtual ~FragTrap();
	
	public:
		void highFivesGuys(void);
};

#endif