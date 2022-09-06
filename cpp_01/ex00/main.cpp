#include "Zombie.hpp"

int	main(void) {
	Zombie *zmb1 = newZombie("JOoooooHN");
	zmb1->announce();
	randomChump("Booooooob");
	delete zmb1;
	return 0;
}