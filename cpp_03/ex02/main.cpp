#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	FragTrap pers_one("pers_one");
  	ScavTrap pers_two("pers_two");
	pers_one.highFivesGuys();

	pers_one.attack(pers_two.getName());
	pers_two.takeDamage(pers_one.getAttackDamage());

	pers_one.attack(pers_two.getName());
	pers_two.takeDamage(pers_one.getAttackDamage());

	pers_one.attack(pers_two.getName());
	pers_two.takeDamage(pers_one.getAttackDamage());

	pers_two.beRepaired(42);
}