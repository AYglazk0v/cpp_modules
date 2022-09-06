#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : human_name_(name), human_weapon_(NULL) {};

HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon& newWeapon) {
	human_weapon_ = &newWeapon;
}

void HumanB::attack(void) {
	if (human_weapon_) {
		std::cout << human_name_ << " attacks with a " << human_weapon_->getType() << std::endl;
	} else {
		std::cout << human_name_ << " attacks unarmed" << std::endl;
	}
}