/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:05:11 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/14 17:18:37 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "Constructors and highFivesGuys only for FragTrap" << std::endl << std::endl;

    ClapTrap    skibidi("Skibidi");
    ScavTrap    fortnite("Fortnite");
    FragTrap    pubg("PUBG");

    pubg.highFivesGuys();
    
    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Attack for all 3" << std::endl << std::endl;

    skibidi.attack("Fortnite");
    fortnite.attack("PUBG");
    pubg.attack("Skibidi");

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Take damage for all 3" << std::endl << std::endl;

    skibidi.takeDamage(100);
    fortnite.takeDamage(3);
    pubg.takeDamage(30);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Be repaired for the two that are not dead" << std::endl << std::endl;

    fortnite.beRepaired(20);
    pubg.beRepaired(40);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Assignation operator and highFivesGuys for FragTrap and attack still 30" << std::endl << std::endl;

    FragTrap    pubg2(pubg);
    pubg2 = pubg;
    pubg2.highFivesGuys();
    pubg2.attack("Skibidi");

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Destructors" << std::endl << std::endl;

    return 0;
}