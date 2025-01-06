/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:20:53 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/06 12:13:47 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie* heapZombie = newZombie("omgomg");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Hello I am under the water");

	return (0);
}
