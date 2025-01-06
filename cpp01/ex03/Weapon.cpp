/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:36:36 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/06 13:41:22 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type)
{
    std::cout << "Weapon created" << std::endl;   
}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}
