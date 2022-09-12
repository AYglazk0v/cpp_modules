#include "DiamondTrap.hpp"

void DiamondTrap::SetDefaultPoints() {
	hitpoints_ = FragTrap::hitpoints_;
	energy_points_ = ScavTrap::energy_points_;
	attack_damage_ = FragTrap::attack_damage_;
	std::cout << "It has: \n HP = " << hitpoints_
			<< "\n energy points = " << energy_points_
			<< "\n atack damage = " << attack_damage_ << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"),
													FragTrap(name),
													ScavTrap(name),
													name_(name) {
	std::cout << "[ Diamond Dirent ctor ]" << std::endl;
	std::cout << "DiamondTrap " << name_ << " is created" << std::endl;
	SetDefaultPoints();
}

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), name_("DEFAULT") {
	ClapTrap::name_ = name_ + "_clap_name";
	std::cout << "[ Diamond Default ctor ]" << std::endl;
	SetDefaultPoints();
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[ Diamond Destr ]" << std::endl;
	std::cout << name_ << " was destroy." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs) {
	*this = rhs;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
	if (this == &rhs){
		return  *this;
	}
	name_ = rhs.name_;
	hitpoints_ = rhs.FragTrap::hitpoints_;
	energy_points_ = rhs.ScavTrap::energy_points_;
	attack_damage_ = rhs.FragTrap::attack_damage_;
	return *this;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "My name: " << name_
			<< ", My ClapTrap name: " << ClapTrap::name_
			<< std::endl;
}