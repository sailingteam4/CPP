/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 23:40:43 by nrontey           #+#    #+#             */
/*   Updated: 2024/08/12 05:56:35 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					std::cout << (char)toupper(av[i][j]);
				else
					std::cout << (char)av[i][j];
		}
		std::cout << std::endl;
	}
	return (0);
}
