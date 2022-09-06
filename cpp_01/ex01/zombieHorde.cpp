#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie *legion = new Zombie[N];
	for (int i = 0; i != N; ++i) {
		legion[i].setName(name, i);
	}
	return legion;
}