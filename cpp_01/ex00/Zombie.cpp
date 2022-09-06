#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name_(name) {}

Zombie::~Zombie() {
	std::cout << name_ << ": I'm DECAY!" << std::endl;
}

void Zombie::announce() const {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}