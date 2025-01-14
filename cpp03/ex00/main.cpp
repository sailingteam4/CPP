/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:05:11 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/14 16:20:10 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "Testing ClapTrap initialization" << std::endl << std::endl;

    ClapTrap    noname;
    ClapTrap    skibidi("Skibidi");
    ClapTrap    fortnite("Fortnite");
    ClapTrap    copy(fortnite);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Testing Damage and can't be repaired" << std::endl << std::endl;

    noname.takeDamage(500);
    noname.takeDamage(1);
    noname.takeDamage(-400);
    noname.beRepaired(5);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Testing Damage and can be repaired" << std::endl << std::endl;

    skibidi.takeDamage(2);
    skibidi.beRepaired(5);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Testing not enough energy" << std::endl << std::endl;

    fortnite.takeDamage(9);
    fortnite.beRepaired(20);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Testing enough energy and not enough" << std::endl << std::endl;

    fortnite.beRepaired(5);
    fortnite.beRepaired(10);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Testing enough energy and attack until not enough" << std::endl << std::endl;

    copy.attack("Skibidi");
    copy.attack("Fortnite");
    copy.attack("Fortnite");
    copy.attack("Fortnite");
    copy.attack("Fortnite");
    copy.attack("Fortnite");
    copy.takeDamage(1);
    copy.beRepaired(1);
    copy.attack("Fortnite");
    copy.attack("Fortnite");
    copy.attack("Fortnite");
    copy.attack("Fortnite");
    copy.attack("Fortnite");
    copy.beRepaired(1);

    std::cout << "____________________________________________________" << std::endl << std::endl;
    std::cout << "Destructor" << std::endl << std::endl;

    return 0;
}