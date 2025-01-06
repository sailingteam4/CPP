/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:31:02 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/06 12:35:20 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* hordeArr = new Zombie[N];

	for(int i = 0; i < N; i++) {
		hordeArr[i].setZombieName(name);
	}

	return hordeArr;
}
