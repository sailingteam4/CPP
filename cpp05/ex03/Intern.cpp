/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:21:00 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/12 00:26:36 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& src) {
    (void)src;
    std::cout << "Intern copy created" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destroyed" << std::endl;
}

Intern& Intern::operator=(const Intern& src) {
    (void)src;
    return *this;
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form type not found";
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formTypes[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (Intern::*formCreators[])(std::string) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };
    
    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            AForm* form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    
    throw FormNotFoundException();
    return NULL;
}

AForm* Intern::createShrubberyForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(std::string target) {
    return new PresidentialPardonForm(target);
}
