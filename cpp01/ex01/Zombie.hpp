/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:30:59 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/06 12:32:22 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		void setZombieName(std::string zombieName);
		void announce(void);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif
