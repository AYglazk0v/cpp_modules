#include "ScavTrap.hpp"

int main() {
	ClapTrap pers_one("pers_one");
	ScavTrap pers_two("pers_two");

	pers_two.guardGate();
	pers_two.attack(pers_one.getName());
	pers_one.takeDamage(pers_two.getAttackDamage());
	pers_two.beRepaired(20);
	pers_one.attack(pers_two.getName());
	pers_one.beRepaired(20);
	pers_one.attack(pers_two.getName());
	pers_one.takeDamage(pers_one.getAttackDamage());
}