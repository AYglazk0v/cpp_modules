#include "Zombie.hpp"

Zombie::Zombie() : name_("default_NAME") {
	std::cout << "What is dead cannot kill" << std::endl;
}

Zombie::Zombie(const std::string& name) : name_(name) {
	std::cout << Zombie::name_ << "What is dead cannot kill" << std::endl;
}

Zombie::~Zombie() {
	std::cout << name_ << "#" << id_ << ": I'm DECAY!" << std::endl;
}

void Zombie::announce() const {
	std::cout << name_ << "#" << id_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name, const int id) {
	Zombie::name_ = name;
	Zombie::id_ = id;
}

std::string Zombie::getName() {
	return this->name_;
}