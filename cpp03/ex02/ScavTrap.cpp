/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:50:48 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/13 19:53:01 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    std::cout << "ScavTrap " << this->_name << " copy constructor called" << std::endl;
}

ScavTrap&       ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints -= 1;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot attack" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->_name << " is out of energy and cannot attack" << std::endl;
    }
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}
