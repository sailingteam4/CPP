/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:40:30 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/06 13:40:46 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA
{
    private:
        std::string name;
        Weapon&     weapon;

    public:
        HumanA(const std::string& name, Weapon& weapon);

        void        attack() const;
};

#endif
