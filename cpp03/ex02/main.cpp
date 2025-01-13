/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:05:11 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/13 21:09:46 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap    skibidi("Skibidi");
    ScavTrap    fortnite("Fortnite");
    FragTrap    pubg("PUBG");

    pubg.highFivesGuys();
    
    std::cout << "____________________________________________________" << std::endl << std::endl;

    skibidi.attack("Fortnite");
    fortnite.attack("PUBG");
    pubg.attack("Skibidi");

    std::cout << "____________________________________________________" << std::endl << std::endl;

    skibidi.takeDamage(100);
    fortnite.takeDamage(3);
    pubg.takeDamage(30);

    std::cout << "____________________________________________________" << std::endl << std::endl;

    fortnite.beRepaired(20);
    pubg.beRepaired(40);

    std::cout << "____________________________________________________" << std::endl << std::endl;

    FragTrap    pubg2(pubg);
    pubg2 = pubg;
    pubg2.highFivesGuys();
    pubg2.attack("Skibidi");

    return 0;
}