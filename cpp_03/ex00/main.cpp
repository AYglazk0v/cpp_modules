#include "ClapTrap.hpp"

int main()
{
  ClapTrap pers_one("pers_one");
  ClapTrap pers_two("pers_two");

  pers_one.attack(pers_two.getName());
  pers_two.takeDamage(pers_one.getAttackDamage());
  pers_two.beRepaired(10);

}