/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:57:00 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/11 23:19:02 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void printTitle(const std::string& title) {
    std::cout << MAGENTA << "\n=== " << title << " ===" << RESET << std::endl;
}

void testFormCreation() {
    printTitle("FORM CREATION TESTS");
    
    try {
        std::cout << BLUE << "\nTesting ShrubberyCreationForm creation:" << RESET << std::endl;
        ShrubberyCreationForm s("garden");
        std::cout << GREEN << "Success: Created ShrubberyCreationForm" << RESET << std::endl;

        std::cout << BLUE << "\nTesting RobotomyRequestForm creation:" << RESET << std::endl;
        RobotomyRequestForm r("human");
        std::cout << GREEN << "Success: Created RobotomyRequestForm" << RESET << std::endl;

        std::cout << BLUE << "\nTesting PresidentialPardonForm creation:" << RESET << std::endl;
        PresidentialPardonForm p("criminal");
        std::cout << GREEN << "Success: Created PresidentialPardonForm" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

void testShrubberyCreation() {
    printTitle("SHRUBBERY CREATION FORM TEST");
    
    try {
        Bureaucrat highGrade("Boss", 1);
        Bureaucrat lowGrade("Intern", 150);
        ShrubberyCreationForm form("garden");

        std::cout << CYAN << "\nTrying to execute without signing:" << RESET << std::endl;
        highGrade.executeForm(form);

        std::cout << CYAN << "\nLow grade trying to sign:" << RESET << std::endl;
        lowGrade.signAForm(form);

        std::cout << CYAN << "\nHigh grade signing:" << RESET << std::endl;
        highGrade.signAForm(form);

        std::cout << CYAN << "\nLow grade trying to execute:" << RESET << std::endl;
        lowGrade.executeForm(form);

        std::cout << CYAN << "\nHigh grade executing:" << RESET << std::endl;
        highGrade.executeForm(form);
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

void testRobotomy() {
    printTitle("ROBOTOMY REQUEST FORM TEST");
    
    try {
        Bureaucrat highGrade("Director", 1);
        RobotomyRequestForm form("subject");

        std::cout << CYAN << "\nSigning form:" << RESET << std::endl;
        highGrade.signAForm(form);

        std::cout << CYAN << "\nExecuting robotomy multiple times:" << RESET << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << YELLOW << "\nAttempt " << i + 1 << ":" << RESET << std::endl;
            highGrade.executeForm(form);
        }
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

void testPresidentialPardon() {
    printTitle("PRESIDENTIAL PARDON FORM TEST");
    
    try {
        Bureaucrat president("President", 1);
        Bureaucrat secretary("Secretary", 25);
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm form("criminal");

        std::cout << CYAN << "\nIntern trying to sign:" << RESET << std::endl;
        intern.signAForm(form);

        std::cout << CYAN << "\nSecretary signing:" << RESET << std::endl;
        secretary.signAForm(form);

        std::cout << CYAN << "\nIntern trying to execute:" << RESET << std::endl;
        intern.executeForm(form);

        std::cout << CYAN << "\nSecretary trying to execute:" << RESET << std::endl;
        secretary.executeForm(form);

        std::cout << CYAN << "\nPresident executing:" << RESET << std::endl;
        president.executeForm(form);
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

void testInvalidExecution() {
    printTitle("INVALID EXECUTION TESTS");
    
    try {
        Bureaucrat mid("Manager", 75);
        ShrubberyCreationForm s("home");
        RobotomyRequestForm r("robot");
        PresidentialPardonForm p("person");

        std::cout << CYAN << "\nTrying to execute unsigned forms:" << RESET << std::endl;
        mid.executeForm(s);
        mid.executeForm(r);
        mid.executeForm(p);

        std::cout << CYAN << "\nSigning forms:" << RESET << std::endl;
        mid.signAForm(s);
        mid.signAForm(r);
        mid.signAForm(p);

        std::cout << CYAN << "\nTrying to execute forms with insufficient grade:" << RESET << std::endl;
        mid.executeForm(p);  // Should fail (requires grade 5)
        mid.executeForm(r);  // Should fail (requires grade 45)
        mid.executeForm(s);  // Should succeed (requires grade 137)
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

int main()
{
    testFormCreation();
    testShrubberyCreation();
    testRobotomy();
    testPresidentialPardon();
    testInvalidExecution();

    return 0;
}
