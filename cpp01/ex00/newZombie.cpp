#include "Zombie.hpp"

Zombie*	Zombie::newZombie(str name) {
	Zombie	*zombie = new Zombie(name);
	zombie->announce();
	return zombie;
}
