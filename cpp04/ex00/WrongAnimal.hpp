/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:59:47 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/16 14:19:04 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string     _type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal     &operator=(const WrongAnimal &other);
        ~WrongAnimal();

        std::string     getType() const;
        void            makeSound() const;
};

#endif
