#include "Zombie.hpp"

int	main() {
	Zombie	*z = NULL;

	z = z->newZombie("Zombie1");
	z->randomChump("Zombie2");
	delete z;
}
