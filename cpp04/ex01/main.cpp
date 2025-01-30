/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:04:32 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/16 14:27:04 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

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
	std::cout << YELLOW << "----- Basic constructor tests -----" << RESET << std::endl << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << YELLOW << "----- Basic destructor tests -----" << RESET << std::endl << std::endl;

	delete j;
	delete i;

	std::cout << std::endl << YELLOW << "----- Arrays tests -----" << RESET << std::endl << std::endl;

	const int n = 4;
	std::cout << GREEN << "Creating an array of " << n << " animals" << RESET << std::endl;
	Animal* animals[n];

	std::cout << std::endl << GREEN << "Creating " << n / 2 << " dogs" << RESET << std::endl << std::endl;

	for (int i = 0; i < n / 2; i++)
	{
		animals[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << std::endl << GREEN << "Creating " << n / 2 << " cats" << RESET << std::endl << std::endl;

	for (int i = n / 2; i < n; i++)
	{
		animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << std::endl << RED << "Deleting all animals" << RESET << std::endl << std::endl;

	for (int i = 0; i < n; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << std::endl << YELLOW << "----- Copy constructor tests -----" << RESET << std::endl << std::endl;

	Dog dog;
	Dog dog2(dog);

	std::cout << std::endl;

	Cat cat;
	Cat cat2(cat);

	std::cout << std::endl << YELLOW << "----- Assignation operator tests -----" << RESET << std::endl << std::endl;

	Dog dog3;
	Dog dog4;

	dog4 = dog3;

	std::cout << std::endl;

	Cat cat3;
	Cat cat4;

	cat4 = cat3;

	std::cout << std::endl << YELLOW << "----- WrongAnimal tests -----" << RESET << std::endl << std::endl;

	WrongAnimal* test = new WrongAnimal();
	Cat* cat5 = new Cat();

	cat5->makeSound();
	test->makeSound();

	std::cout << std::endl << YELLOW << "----- WrongAnimal destructor tests -----" << RESET << std::endl << std::endl;

	delete test;

	std::cout << std::endl << YELLOW << "----- Cat destructor tests -----" << RESET << std::endl << std::endl;

	delete cat5;

	std::cout << YELLOW << "----- Destructors here -----" << RESET << std::endl;

	return 0;
}
