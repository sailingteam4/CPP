/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:37:48 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/06 13:38:53 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB
{
    private:
        std::string name;
        Weapon*     weapon;

    public:
        HumanB(const std::string& name);

        void        setWeapon(Weapon& weapon);
        void        attack() const;
};

#endif
