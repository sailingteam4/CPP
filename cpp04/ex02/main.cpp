/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:04:32 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/16 14:28:11 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{
	std::cout << YELLOW << "----- Test AAnimal can't be instantiated -----" << RESET << std::endl << std::endl;

	//AAnimal test; // This line will not compile

	std::cout << GREEN << "----- Basic constructor tests -----" << RESET << std::endl << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << std::endl << RED << "----- Basic destructor tests -----" << RESET << std::endl << std::endl;

	delete j;
	delete i;

	std::cout << std::endl << BLUE << "----- Arrays tests -----" << RESET << std::endl << std::endl;

	const int n = 4;
	std::cout << "Creating an array of " << n << " animals" << std::endl;
	AAnimal* animals[n];

	std::cout << std::endl << "Creating " << n / 2 << " dogs" << std::endl << std::endl;

	for (int i = 0; i < n / 2; i++)
	{
		animals[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Creating " << n / 2 << " cats" << std::endl << std::endl;

	for (int i = n / 2; i < n; i++)
	{
		animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << std::endl << MAGENTA << "Deleting all animals" << RESET << std::endl << std::endl;

	for (int i = 0; i < n; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << std::endl << CYAN << "----- Copy constructor tests -----" << RESET << std::endl << std::endl;

	Dog dog;
	Dog dog2(dog);

	std::cout << std::endl;

	Cat cat;
	Cat cat2(cat);

	std::cout << std::endl << WHITE << "----- Assignation operator tests -----" << RESET << std::endl << std::endl;

	Dog dog3;
	Dog dog4;

	dog4 = dog3;

	std::cout << std::endl;

	Cat cat3;
	Cat cat4;

	cat4 = cat3;

	std::cout << YELLOW << "----- End of tests destructors here -----" << RESET << std::endl;

	return 0;
}
