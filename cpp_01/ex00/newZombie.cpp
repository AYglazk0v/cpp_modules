#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie *zombie_ = new Zombie(name);
	return zombie_;
}