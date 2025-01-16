/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:04:32 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/16 14:12:14 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- Basic constructor tests -----" << std::endl << std::endl;

    const Animal* j = new Dog();
	const Animal* i = new Cat();

    std::cout << std::endl << "----- Basic destructor tests -----" << std::endl << std::endl;

    delete j;
	delete i;

    std::cout << std::endl << "----- Arrays tests -----" << std::endl << std::endl;

    const int n = 4;
    std::cout << "Creating an array of " << n << " animals" << std::endl;
    Animal* animals[n];

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

    std::cout << std::endl << "Deleting all animals" << std::endl << std::endl;

    for (int i = 0; i < n; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }

    std::cout << std::endl << "----- Copy constructor tests -----" << std::endl << std::endl;

    Dog dog;
    Dog dog2(dog);

    std::cout << std::endl;

    Cat cat;
    Cat cat2(cat);

    std::cout << std::endl << "----- Assignation operator tests -----" << std::endl << std::endl;

    Dog dog3;
    Dog dog4;

    dog4 = dog3;

    std::cout << std::endl;

    Cat cat3;
    Cat cat4;

    cat4 = cat3;

	std::cout << std::endl << "----- WrongAnimal tests -----" << std::endl << std::endl;

	WrongAnimal* test = new WrongAnimal();
	Cat* cat5 = new Cat();

	cat5->makeSound();
	test->makeSound();

	std::cout << std::endl << "----- WrongAnimal destructor tests -----" << std::endl << std::endl;

	delete test;

	std::cout << std::endl << "----- Cat destructor tests -----" << std::endl << std::endl;

	delete cat5;

    std::cout << "----- Destructors here -----" << std::endl;

    return 0;
}
