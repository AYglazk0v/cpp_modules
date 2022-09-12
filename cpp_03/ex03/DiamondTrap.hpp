#ifndef DIAMONDTRAP_HPP

# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string name_;
		void SetDefaultPoints();

	public:
		DiamondTrap();
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& rhs);
		DiamondTrap& operator=(const DiamondTrap& rhs);
		virtual ~DiamondTrap();

	public:
		void whoAmI();
		void attack(const std::string& target);
};

#endif