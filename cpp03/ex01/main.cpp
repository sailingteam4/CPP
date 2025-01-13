/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:05:11 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/13 19:58:44 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap    skibidi("Skibidi");
    ScavTrap    fortnite("Fortnite");

    std::cout << "____________________________________________________" << std::endl << std::endl;

    skibidi.attack("Fortnite");
    fortnite.attack("Skibidi");

    std::cout << "____________________________________________________" << std::endl << std::endl;

    skibidi.takeDamage(3);
    fortnite.takeDamage(10);

    std::cout << "____________________________________________________" << std::endl << std::endl;

    skibidi.beRepaired(5);
    fortnite.beRepaired(20);

    std::cout << "____________________________________________________" << std::endl << std::endl;

    fortnite.guardGate();

    std::cout << "____________________________________________________" << std::endl << std::endl;

    for (int i = 0; i < 30; i++)
        fortnite.attack("Skibidi");

    std::cout << "____________________________________________________" << std::endl << std::endl;

    fortnite.attack("Skibidi");
    fortnite.beRepaired(10);

    std::cout << "____________________________________________________" << std::endl << std::endl;

    ScavTrap    me("Me");
    me = fortnite;
    me.attack("Skibidi");
    
    return 0;
}