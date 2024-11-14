#include "Zombie.hpp"

int	main() {
    Zombie	*horde = zombieHorde(5, "nrontey");
    delete[] horde;
    return 0;
}
