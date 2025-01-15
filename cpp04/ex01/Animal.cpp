/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:19:46 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/13 23:53:28 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") 
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) 
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) 
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "Animal assignation operator called" << std::endl;
    return *this;
}

Animal::~Animal() 
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const 
{
    return _type;
}

void Animal::makeSound() const 
{
    std::cout << "Animal sound" << std::endl;
}
