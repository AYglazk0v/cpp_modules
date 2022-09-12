#ifndef CLAPTRAP_HPP

# define  CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

	private:
		std::string name_;
		int hitpoints_;
		int energy_points_;
		int attack_damage_;

	public:
	 	ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& rhs);
		ClapTrap& operator=(const ClapTrap& rhs);
		virtual ~ClapTrap();

	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	public:
		const int& getHitPoints();
		const int& getEnergyPoints();
		const int& getAttackDamage();
		const std::string& getName();
};

#endif