/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:57:00 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/12 00:48:23 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void testFormCreation(const std::string& name, int signGrade, int execGrade) {
    try {
        std::cout << BLUE << "\nTesting Form creation: " << name 
                 << " (Sign: " << signGrade << ", Exec: " << execGrade << ")" << RESET << std::endl;
        Form f(name, signGrade, execGrade);
        std::cout << GREEN << "Success: " << f << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

void testFormSigning(const std::string& bureaucratName, int bureaucratGrade,
                    const std::string& FormName, int FormSignGrade, int FormExecGrade) {
    try {
        Bureaucrat b(bureaucratName, bureaucratGrade);
        Form f(FormName, FormSignGrade, FormExecGrade);
        
        std::cout << BLUE << "\nTesting Form signing:" << RESET << std::endl;
        std::cout << CYAN << "Bureaucrat: " << b << RESET << std::endl;
        std::cout << CYAN << "Form: " << f << RESET << std::endl;
        
        b.signForm(f);
        std::cout << GREEN << "After signing attempt: " << f << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

int main()
{
    printTitle("Form CREATION TESTS");
    
    testFormCreation("Normal Form", 75, 75);
    testFormCreation("High Grade Form", 1, 1);
    testFormCreation("Low Grade Form", 150, 150);
    testFormCreation("Invalid High Form", 0, 75);
    testFormCreation("Invalid Low Form", 151, 75);
    testFormCreation("Mixed Grades Form", 100, 50);

    printTitle("Form SIGNING TESTS");

    // Test successful signing
    testFormSigning("Manager", 1, "Easy Form", 75, 75);
    
    // Test failed signing due to low grade
    testFormSigning("Intern", 150, "Difficult Form", 1, 1);
    
    // Test signing with edge cases
    testFormSigning("Supervisor", 50, "Medium Form", 50, 50);

    printTitle("Form COPY AND ASSIGNMENT TESTS");

    try {
        Form original("Original", 42, 42);
        std::cout << CYAN << "Original: " << original << RESET << std::endl;
        
        Form copy(original);
        std::cout << CYAN << "Copy: " << copy << RESET << std::endl;
        
        Form assigned("Temp", 100, 100);
        assigned = original;
        std::cout << CYAN << "Assigned: " << assigned << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    printTitle("MULTIPLE SIGNING ATTEMPTS TEST");

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Form important("Important Document", 50, 50);

        std::cout << YELLOW << "\nInitial Form state:" << RESET << std::endl;
        std::cout << important << std::endl;

        std::cout << YELLOW << "\nIntern trying to sign:" << RESET << std::endl;
        intern.signForm(important);

        std::cout << YELLOW << "\nBoss trying to sign:" << RESET << std::endl;
        boss.signForm(important);

        std::cout << YELLOW << "\nBoss trying to sign again:" << RESET << std::endl;
        boss.signForm(important);
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }


    return 0;
}
