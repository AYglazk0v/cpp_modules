#include "FragTrap.hpp"

void FragTrap::SetDefaultPoints() {
	hitpoints_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "It has: \n HP = " << hitpoints_
			<< "\n energy points = " << energy_points_
			<< "\n atack damage = " << attack_damage_ << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "[ Frag Dirent ctor ]" << std::endl;
	std::cout << "FragTrap " << name_ << " is created" << std::endl;
	SetDefaultPoints();
}

FragTrap::~FragTrap() {
	std::cout << "[ Frag Destr ]" << std::endl;
	std::cout << name_ << " was destroy." << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs) {
	std::cout << "[ Frag Copy ctor ]" << std::endl;
	*this = rhs;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if (this == &rhs){
		return *this;
	}
	name_ = rhs.name_;
	hitpoints_ = rhs.hitpoints_;
	energy_points_ = rhs.hitpoints_;
	attack_damage_ = rhs.attack_damage_;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "Hey! I am " << name_ <<  " - take high five" << std::endl;
}

FragTrap::FragTrap() {
	std::cout << "[ Frag Default ctor ]" << std::endl;
	SetDefaultPoints();
}