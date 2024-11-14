#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "The zombie " << name << " is here !" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "A zombie died a second time." << std::endl;
}

void	Zombie::announce() const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(str name) {
	this->name = name;
}
