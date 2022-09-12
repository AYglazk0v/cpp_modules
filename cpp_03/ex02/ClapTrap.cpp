#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("Default"),
						hitpoints_(10),
						energy_points_(10),
						attack_damage_(0) {
	std::cout << "[ Clap Default ctor ]" << std::endl;
	std::cout << "ClapTrap" << name_ << " is created." << std::endl;
	std::cout << "It has: \n HP = " << hitpoints_
			<< "\n energy points = " << energy_points_
			<< "\n atack damage = " << attack_damage_ << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name_(name),
											hitpoints_(10),
											energy_points_(10),
											attack_damage_(0) {
	std::cout << "[ Clap Dirent ctor ]" << std::endl;
	std::cout << "ClapTrap" << name_ << " is created." << std::endl;
	std::cout << "It has: \n HP = " << hitpoints_
			<< "\n energy points = " << energy_points_
	<< "\n atack damage = " << attack_damage_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) : name_(rhs.name_),
										hitpoints_(rhs.hitpoints_),
										energy_points_(rhs.hitpoints_),
										attack_damage_(rhs.attack_damage_) {
	std::cout << "[ Clap Copy ctor ]" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "[ Clap Destr ]" << std::endl;
	std::cout << name_ << " was destroy." << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "[ Clap Assiassignment ]" << std::endl;
	if (this == &rhs) {
		return *this;
	}
	name_ = rhs.name_;
	energy_points_ = rhs.energy_points_;
	attack_damage_ = rhs.attack_damage_;
	hitpoints_ = rhs.hitpoints_;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (energy_points_ <= 0 || hitpoints_ <= 0) {
		if (energy_points_ <= 0) {
			std::cout << "ClapTrap " << name_ << " has no energy points"
			<< "to attack." << std::endl;
		}
		if (hitpoints_ <= 0) {
			std::cout << "ClapTrap " << name_ << "has no hitpoints"
			<< "to attack." << std::endl;
		}
	} else {
		std::cout << "ClapTrap " << name_ << " attack " << target
		<< ", causing " << attack_damage_ << " points of damage!" << std::endl;
		energy_points_--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitpoints_ -=amount;
	std::cout << "ClapTrap " << name_ << " damage to "
			<< amount << " points" << std::endl;
	if (hitpoints_ <= 0) {
		std::cout << "It has no more hitpoints" << std::endl;
	} else {
		std::cout << "Now it has: " << hitpoints_ << " hitpoints" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (energy_points_ <= 0) {
		std::cout << "ClapTrap " << name_ << " has no energy points"
				<< " to repair itself" << std::endl;
	} else {
		energy_points_--;
		hitpoints_ += amount;
		std::cout << "ClapTrap " << name_ << " received " << amount
			<< " hitpoints back.\n" << "Now it has: "
			<< hitpoints_ << " hitpoints" << std::endl;
	}
}

const int& ClapTrap::getAttackDamage() {
	return attack_damage_;
}

const int& ClapTrap::getEnergyPoints() {
	return energy_points_;
}

const int& ClapTrap::getHitPoints() {
	return hitpoints_;
}

const std::string& ClapTrap::getName() {
	return name_;
}
