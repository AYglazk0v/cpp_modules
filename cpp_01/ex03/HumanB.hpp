#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	private:
		std::string human_name_;
		Weapon	*human_weapon_;
	
	public:
		HumanB(const std::string& human_name);
		~HumanB();
	
	public:
		void setWeapon(Weapon& new_weapon_);
		void attack(void);
};

#endif