#include "DiamondTrap.hpp"

int main()
{
  DiamondTrap person_one("person_one");
  person_one.whoAmI();

  ScavTrap person_two("person_two");

  person_one.attack(person_two.getName());
  person_two.takeDamage(person_one.getAttackDamage());
  person_one.highFivesGuys();
  person_one.guardGate();
  person_one.beRepaired(50);
}