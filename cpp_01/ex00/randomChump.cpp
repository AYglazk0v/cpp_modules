#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie zombie_(name);
	zombie_.announce();
}