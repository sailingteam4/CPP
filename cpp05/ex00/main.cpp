#include "Bureaucrat.hpp"
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
	std::cout << BOLD << CYAN << "=== Bureaucrat Testing ===" << RESET << std::endl;

	std::cout << BOLD << GREEN << "\n--- Test 1: Valid bureaucrat creation ---" << RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << BLUE << bob << RESET << std::endl;
		
		Bureaucrat alice("Alice", 1);
		std::cout << BLUE << alice << RESET << std::endl;
		
		Bureaucrat charlie("Charlie", 150);
		std::cout << BLUE << charlie << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << YELLOW << "\n--- Test 2: Invalid grade - too high ---" << RESET << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << BLUE << invalid << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << YELLOW << "\n--- Test 3: Invalid grade - too low ---" << RESET << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << BLUE << invalid << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << MAGENTA << "\n--- Test 4: Grade increment ---" << RESET << std::endl;
	try
	{
		Bureaucrat dave("Dave", 50);
		std::cout << GREEN << "Before increment: " << RESET << dave << std::endl;
		dave.incrementGrade();
		std::cout << CYAN << "After increment: " << RESET << dave << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << MAGENTA << "\n--- Test 5: Grade decrement ---" << RESET << std::endl;
	try
	{
		Bureaucrat eve("Eve", 50);
		std::cout << GREEN << "Before decrement: " << RESET << eve << std::endl;
		eve.decrementGrade();
		std::cout << CYAN << "After decrement: " << RESET << eve << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << RED << "\n--- Test 6: Grade increment overflow ---" << RESET << std::endl;
	try
	{
		Bureaucrat topBureaucrat("Top", 1);
		std::cout << GREEN << "Before increment: " << RESET << topBureaucrat << std::endl;
		topBureaucrat.incrementGrade();
		std::cout << CYAN << "After increment: " << RESET << topBureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << RED << "\n--- Test 7: Grade decrement overflow ---" << RESET << std::endl;
	try
	{
		Bureaucrat bottomBureaucrat("Bottom", 150);
		std::cout << GREEN << "Before decrement: " << RESET << bottomBureaucrat << std::endl;
		bottomBureaucrat.decrementGrade();
		std::cout << CYAN << "After decrement: " << RESET << bottomBureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BOLD << WHITE << "\n--- Test 8: Copy constructor and assignment ---" << RESET << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		std::cout << YELLOW << "Original: " << RESET << original << std::endl;

		Bureaucrat copy(original);
		std::cout << BLUE << "Copy: " << RESET << copy << std::endl;

		Bureaucrat assigned("TempName", 100);
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
