/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:51:00 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/13 16:01:10 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPPTRAP_HPP
#define CLAPPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;

    public:
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap&       operator=(const ClapTrap& other);
        ~ClapTrap();

        void            attack(const std::string& target);
        void            takeDamage(unsigned int amount);
        void            beRepaired(unsigned int amount);
        
};

#endif