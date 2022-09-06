#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

	private:
		std::string human_name_;
		Weapon& human_weapon_;
	
	public:
		HumanA(const std::string& name, Weapon& Weapon);
		~HumanA();
	
	public:
		void setWeapon(const Weapon& new_weapon);
		void attack(void);
};

#endif