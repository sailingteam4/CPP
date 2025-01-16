/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:04:32 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/16 14:20:03 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

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
	std::cout << YELLOW << "----- Constructor tests -----" << RESET << std::endl << std::endl;

	std::cout << GREEN << "Creating Animal objects: " << RESET << std::endl << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl << GREEN << "Creating Dog objects: " << RESET << std::endl << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl << GREEN << "Creating Cat objects: " << RESET << std::endl << std::endl;
	const Animal* i = new Cat();

	std::cout << std::endl << YELLOW << "----- Sound tests -----" << RESET << std::endl << std::endl;

	std::cout << BLUE << "Calling makeSound() on Cat objects: " << RESET << std::endl << std::endl;
	i->makeSound();
	std::cout << BLUE << "Calling makeSound() on Dog objects: " << RESET << std::endl << std::endl;
	j->makeSound();
	std::cout << BLUE << "Calling makeSound() on Animal objects: " << RESET << std::endl << std::endl;
	meta->makeSound();

	std::cout << std::endl << YELLOW << "----- Constructors tests -----" << RESET << std::endl << std::endl;

	std::cout << GREEN << "Creating WrongAnimal object: " << RESET << std::endl << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	std::cout << std::endl << GREEN << "Creating WrongCat object: " << RESET << std::endl << std::endl;
	const WrongAnimal* wrong_j = new WrongCat();

	std::cout << std::endl << YELLOW << "----- Sound tests -----" << RESET << std::endl << std::endl;

	std::cout << BLUE << "Calling makeSound() on WrongCat object: " << RESET << std::endl << std::endl;
	wrong_j->makeSound();
	std::cout << BLUE << "Calling makeSound() on WrongAnimal object: " << RESET << std::endl << std::endl;
	wrong_meta->makeSound();

	std::cout << std::endl << YELLOW << "----- Destructor tests -----" << RESET << std::endl << std::endl;

	std::cout << RED << "Deleting Animal object: " << RESET << std::endl << std::endl;
	delete meta;
	std::cout << RED << "Deleting Dog object: " << RESET << std::endl << std::endl;
	delete j;
	std::cout << RED << "Deleting Cat object: " << RESET << std::endl << std::endl;
	delete i;
	std::cout << RED << "Deleting WrongAnimal object: " << RESET << std::endl << std::endl;
	delete wrong_meta;
	std::cout << RED << "Deleting WrongCat object: " << RESET << std::endl << std::endl;
	delete wrong_j;

	return 0;
}
