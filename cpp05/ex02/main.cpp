/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:57:00 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/04 16:59:07 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void testAFormCreation(const std::string& name, int signGrade, int execGrade) {
    try {
        std::cout << BLUE << "\nTesting AForm creation: " << name 
                 << " (Sign: " << signGrade << ", Exec: " << execGrade << ")" << RESET << std::endl;
        AForm f(name, signGrade, execGrade);
        std::cout << GREEN << "Success: " << f << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

void testAFormSigning(const std::string& bureaucratName, int bureaucratGrade,
                    const std::string& AFormName, int AFormSignGrade, int AFormExecGrade) {
    try {
        Bureaucrat b(bureaucratName, bureaucratGrade);
        AForm f(AFormName, AFormSignGrade, AFormExecGrade);
        
        std::cout << BLUE << "\nTesting AForm signing:" << RESET << std::endl;
        std::cout << CYAN << "Bureaucrat: " << b << RESET << std::endl;
        std::cout << CYAN << "AForm: " << f << RESET << std::endl;
        
        b.signAForm(f);
        std::cout << GREEN << "After signing attempt: " << f << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

int main()
{
    printTitle("AForm CREATION TESTS");
    
    testAFormCreation("Normal AForm", 75, 75);
    testAFormCreation("High Grade AForm", 1, 1);
    testAFormCreation("Low Grade AForm", 150, 150);
    testAFormCreation("Invalid High AForm", 0, 75);
    testAFormCreation("Invalid Low AForm", 151, 75);
    testAFormCreation("Mixed Grades AForm", 100, 50);

    printTitle("AForm SIGNING TESTS");

    // Test successful signing
    testAFormSigning("Manager", 1, "Easy AForm", 75, 75);
    
    // Test failed signing due to low grade
    testAFormSigning("Intern", 150, "Difficult AForm", 1, 1);
    
    // Test signing with edge cases
    testAFormSigning("Supervisor", 50, "Medium AForm", 50, 50);

    printTitle("AForm COPY AND ASSIGNMENT TESTS");

    try {
        AForm original("Original", 42, 42);
        std::cout << CYAN << "Original: " << original << RESET << std::endl;
        
        AForm copy(original);
        std::cout << CYAN << "Copy: " << copy << RESET << std::endl;
        
        AForm assigned("Temp", 100, 100);
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
        AForm important("Important Document", 50, 50);

        std::cout << YELLOW << "\nInitial AForm state:" << RESET << std::endl;
        std::cout << important << std::endl;

        std::cout << YELLOW << "\nIntern trying to sign:" << RESET << std::endl;
        intern.signAForm(important);

        std::cout << YELLOW << "\nBoss trying to sign:" << RESET << std::endl;
        boss.signAForm(important);

        std::cout << YELLOW << "\nBoss trying to sign again:" << RESET << std::endl;
        boss.signAForm(important);
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }


    return 0;
}
