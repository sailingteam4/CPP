/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:04:32 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/15 16:02:51 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- Constructor tests -----" << std::endl << std::endl;

    std::cout << "Creating Animal objects: " << std::endl << std::endl;
    const Animal* meta = new Animal();
    std::cout << std::endl << "Creating Dog objects: " << std::endl << std::endl;
    const Animal* j = new Dog();
    std::cout << std::endl << "Creating Cat objects: " << std::endl << std::endl;
    const Animal* i = new Cat();

    std::cout << std::endl << "----- Sound tests -----" << std::endl << std::endl;

    std::cout << "Calling makeSound() on Cat objects: " << std::endl << std::endl;
    i->makeSound();
    std::cout << "Calling makeSound() on Dog objects: " << std::endl << std::endl;
    j->makeSound();
    std::cout << "Calling makeSound() on Animal objects: " << std::endl << std::endl;
    meta->makeSound();

    std::cout << std::endl << "----- Constructors tests -----" << std::endl << std::endl;

    std::cout << "Creating WrongAnimal object: " << std::endl << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    std::cout << std::endl << "Creating WrongCat object: " << std::endl << std::endl;
    const WrongAnimal* wrong_j = new WrongCat();

    std::cout << std::endl << "----- Sound tests -----" << std::endl << std::endl;

    std::cout << "Calling makeSound() on WrongCat object: " << std::endl << std::endl;
    wrong_j->makeSound();
    std::cout << "Calling makeSound() on WrongAnimal object: " << std::endl << std::endl;
    wrong_meta->makeSound();

    std::cout << std::endl << "----- Destructor tests -----" << std::endl << std::endl;

    std::cout << "Deleting Animal object: " << std::endl << std::endl;
    delete meta;
    std::cout << "Deleting Dog object: " << std::endl << std::endl;
    delete j;
    std::cout << "Deleting Cat object: " << std::endl << std::endl;
    delete i;
    std::cout << "Deleting WrongAnimal object: " << std::endl << std::endl;
    delete wrong_meta;
    std::cout << "Deleting WrongCat object: " << std::endl << std::endl;
    delete wrong_j;

    return 0;
}
