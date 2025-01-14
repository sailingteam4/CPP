/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:05:11 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/14 17:17:52 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "Constructors" << std::endl << std::endl;

    ClapTrap    skibidi("Skibidi");
    ScavTrap    fortnite("Fortnite");

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Attack and diffrerent damages" << std::endl << std::endl;

    skibidi.attack("Fortnite");
    fortnite.attack("Skibidi");

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Take damage and different remaining hit points" << std::endl << std::endl;

    skibidi.takeDamage(3);
    fortnite.takeDamage(10);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Be repaired and different remaining hit points" << std::endl << std::endl;

    skibidi.beRepaired(5);
    fortnite.beRepaired(20);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Guard gate only for ScavTrap" << std::endl << std::endl;

    fortnite.guardGate();

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Attack 30 times until out of energy" << std::endl << std::endl;

    for (int i = 0; i < 30; i++)
        fortnite.attack("Skibidi");

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Can't attack out of energy and can't repair" << std::endl << std::endl;

    fortnite.attack("Skibidi");
    fortnite.beRepaired(10);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Assignation operator and still out of energy" << std::endl << std::endl;

    ScavTrap    me("Me");
    me = fortnite;
    me.attack("Skibidi");

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Destructors" << std::endl << std::endl;
    
    return 0;
}