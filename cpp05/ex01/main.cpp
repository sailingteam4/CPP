#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

int main()
{
	std::cout << BOLD << CYAN << "=== Form and Bureaucrat Testing ===" << RESET << std::endl;

	std::cout << BOLD << GREEN << "\n--- Test 1: Valid form creation ---" << RESET << std::endl;
	try
	{
		Form taxForm("Tax Form", 50, 25);
		std::cout << BLUE << taxForm << RESET << std::endl;
		
		Form permitForm("Building Permit", 100, 75);
		std::cout << BLUE << permitForm << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << YELLOW << "\n--- Test 2: Invalid form creation - grade too high ---" << RESET << std::endl;
	try
	{
		Form invalidForm("Invalid Form", 0, 50);
		std::cout << BLUE << invalidForm << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << YELLOW << "\n--- Test 3: Invalid form creation - grade too low ---" << RESET << std::endl;
	try
	{
		Form invalidForm("Invalid Form", 151, 50);
		std::cout << BLUE << invalidForm << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << MAGENTA << "\n--- Test 4: Successful form signing ---" << RESET << std::endl;
	try
	{
		Bureaucrat alice("Alice", 30);
		Form requestForm("Request Form", 50, 40);
		
		std::cout << CYAN << "Before signing: " << RESET << requestForm << std::endl;
		alice.signForm(requestForm);
		std::cout << GREEN << "After signing: " << RESET << requestForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << RED << "\n--- Test 5: Failed form signing - grade too low ---" << RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 100);
		Form importantForm("Important Form", 50, 25);
		
		std::cout << CYAN << "Before signing attempt: " << RESET << importantForm << std::endl;
		bob.signForm(importantForm);
		std::cout << YELLOW << "After signing attempt: " << RESET << importantForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << WHITE << "\n--- Test 6: Multiple bureaucrats and forms ---" << RESET << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 1);
		Bureaucrat dave("Dave", 75);
		Bureaucrat eve("Eve", 150);
		
		Form easyForm("Easy Form", 100, 90);
		Form mediumForm("Medium Form", 50, 40);
		Form hardForm("Hard Form", 10, 5);
		
		std::cout << BLUE << "Forms before signing:" << RESET << std::endl;
		std::cout << "  " << easyForm << std::endl;
		std::cout << "  " << mediumForm << std::endl;
		std::cout << "  " << hardForm << std::endl;
		
		std::cout << MAGENTA << "\nCharlie (grade 1) attempts:" << RESET << std::endl;
		charlie.signForm(easyForm);
		charlie.signForm(mediumForm);
		charlie.signForm(hardForm);
		
		std::cout << YELLOW << "\nDave (grade 75) attempts:" << RESET << std::endl;
		dave.signForm(easyForm);
		dave.signForm(mediumForm);
		dave.signForm(hardForm);
		
		std::cout << RED << "\nEve (grade 150) attempts:" << RESET << std::endl;
		eve.signForm(easyForm);
		eve.signForm(mediumForm);
		eve.signForm(hardForm);
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << GREEN << "\n--- Test 7: Copy constructor and assignment ---" << RESET << std::endl;
	try
	{
		Form original("Original Form", 42, 21);
		std::cout << YELLOW << "Original: " << RESET << original << std::endl;

		Form copy(original);
		std::cout << BLUE << "Copy: " << RESET << copy << std::endl;

		Form assigned("Temp Form", 100, 50);
		assigned = original;
		std::cout << MAGENTA << "Assigned: " << RESET << assigned << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << CYAN << "\n=== End of testing ===" << RESET << std::endl;
	return 0;
}
