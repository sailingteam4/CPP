/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:19:46 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/13 23:53:25 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string     _type;

    public:
        Animal();
        Animal(const Animal &other);
        Animal          &operator=(const Animal &other);
        virtual ~Animal();

        std::string     getType() const;
        virtual void    makeSound() const;
};

#endif
