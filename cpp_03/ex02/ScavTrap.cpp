#include "ScavTrap.hpp"

void ScavTrap::SetDefaultPoints() {
	hitpoints_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "It has: \n HP = " << hitpoints_
			<< "\n energy points = " << energy_points_
			<< "\n atack damage = " << attack_damage_ << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "[ Sclav Dirent ctor ]" << std::endl;
	std::cout << "ScavTrap " << name_ << " is created" << std::endl;
	SetDefaultPoints();
}

ScavTrap::~ScavTrap() {
	std::cout << "[ Sclav Destr ]" << std::endl;
	std::cout << name_ << " was destroy." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs) {
	std::cout << "[ Sclab Copy ctor ]" << std::endl;
	*this = rhs;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	if (this == &rhs){
		return *this;
	}
	name_ = rhs.name_;
	hitpoints_ = rhs.hitpoints_;
	energy_points_ = rhs.hitpoints_;
	attack_damage_ = rhs.attack_damage_;
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << name_ << " is staying on Guard Gate" << std::endl;
}

ScavTrap::ScavTrap() {
	std::cout << "[ Sclav Default ctor ]" << std::endl;
	SetDefaultPoints();
}