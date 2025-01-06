/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:30:50 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/06 12:44:05 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int	main()
{
	int N = 3;
	std::string name = "Skibidi";

	Zombie* hordeArr = zombieHorde(N, name);

	for(int i = 0; i < N; i++) {
		hordeArr[i].announce();
	}

	delete[] hordeArr;

	return (0);
}
