/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:01:16 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/13 17:19:09 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " Copy constructor called" << std::endl;
}

ClapTrap&       ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack" << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
        if (amount >= _hitPoints)
        {
            _hitPoints = 0;
            std::cout << "ClapTrap " << _name << " is dead" << std::endl;
        }
        else
        {
            _hitPoints -= amount;
        }
        std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and cannot be repaired" << std::endl;
        return ;
    }
    if (amount > _energyPoints)
    {
        std::cout << "ClapTrap " << _name << " does not have enough energy to be repaired" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " is being repaired for " << amount << " hit points" << std::endl;
    _hitPoints += amount;
    _energyPoints -= amount;
    std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left" << std::endl;
}
