/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:57:00 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/27 18:10:56 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

void testBureaucrat(const std::string& name, int grade) {
    try {
        std::cout << BLUE << "\nTesting Bureaucrat(" << name << ", " << grade << ")" << RESET << std::endl;
        Bureaucrat b(name, grade);
        std::cout << GREEN << "Success: " << b << RESET << std::endl;
        
        std::cout << YELLOW << "Testing promotion..." << RESET << std::endl;
        b.promote();
        std::cout << GREEN << "After promotion: " << b << RESET << std::endl;
        
        std::cout << YELLOW << "Testing demotion..." << RESET << std::endl;
        b.unmote();
        std::cout << GREEN << "After demotion: " << b << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}

int main()
{
    printTitle("BUREAUCRAT TESTS");

    testBureaucrat("Normal Bob", 75);
    testBureaucrat("High Grade Alice", 2);
    testBureaucrat("Low Grade Charlie", 149);

    printTitle("INVALID GRADE TESTS");
    testBureaucrat("Too High Dave", 0);
    testBureaucrat("Too Low Eve", 151);

    printTitle("EDGE CASES TESTS");
    
    try {
        std::cout << BLUE << "\nTesting highest possible grade (1)" << RESET << std::endl;
        Bureaucrat high("Max", 1);
        std::cout << GREEN << high << RESET << std::endl;
        std::cout << YELLOW << "Attempting promotion..." << RESET << std::endl;
        high.promote();
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BLUE << "\nTesting lowest possible grade (150)" << RESET << std::endl;
        Bureaucrat low("Min", 150);
        std::cout << GREEN << low << RESET << std::endl;
        std::cout << YELLOW << "Attempting demotion..." << RESET << std::endl;
        low.unmote();
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    printTitle("COPY AND ASSIGNMENT TESTS");
    
    try {
        Bureaucrat original("Original", 42);
        std::cout << CYAN << "Original: " << original << RESET << std::endl;
        
        Bureaucrat copy(original);
        std::cout << CYAN << "Copy: " << copy << RESET << std::endl;
        
        Bureaucrat assigned;
        assigned = original;
        std::cout << CYAN << "Assigned: " << assigned << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}
