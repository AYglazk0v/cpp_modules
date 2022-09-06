#include "Zombie.hpp"

int main(void) {
	Zombie *horde = zombieHorde(100, "Drew");
	for (int i = 0; i != 100; ++i) {
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}