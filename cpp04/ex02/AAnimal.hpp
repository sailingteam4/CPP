/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:39:03 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/16 00:47:25 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    protected:
        std::string     _type;

    public:
        AAnimal();
        AAnimal(const AAnimal &other);
        AAnimal          &operator=(const AAnimal &other);
        virtual ~AAnimal();

        std::string     getType() const;
        virtual void    makeSound() const = 0;
};

#endif
