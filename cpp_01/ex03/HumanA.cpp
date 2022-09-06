#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& type_weapon) : human_name_(name),
																human_weapon_(type_weapon) {};

HumanA::~HumanA() {};

void HumanA::setWeapon(const Weapon& new_weapon) {
	human_weapon_ = new_weapon;
}

void HumanA::attack(void) {
	std::cout << human_name_ << " attack whit a " << human_weapon_.getType() << std::endl;
}
