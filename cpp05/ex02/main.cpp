#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
	std::cout << BOLD << CYAN << "=== AForm Execution Testing ===" << RESET << std::endl;

	std::cout << BOLD << GREEN << "=== Testing ShrubberyCreationForm ===" << RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 140);
		Bureaucrat alice("Alice", 130);
		ShrubberyCreationForm shrub("garden");
		
		std::cout << BLUE << bob << RESET << std::endl;
		std::cout << YELLOW << shrub << RESET << std::endl;
		
		std::cout << CYAN << "Attempting to sign form:" << RESET << std::endl;
		bob.signForm(shrub);
		std::cout << GREEN << shrub << RESET << std::endl;
		
		std::cout << MAGENTA << "Attempting execution with insufficient grade:" << RESET << std::endl;
		bob.executeForm(shrub); // Should fail
		std::cout << MAGENTA << "Attempting execution with sufficient grade:" << RESET << std::endl;
		alice.executeForm(shrub); // Should succeed
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BOLD << YELLOW << "\n=== Testing RobotomyRequestForm ===" << RESET << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 70);
		Bureaucrat diana("Diana", 40);
		RobotomyRequestForm robot("target");
		
		std::cout << BLUE << charlie << RESET << std::endl;
		std::cout << YELLOW << robot << RESET << std::endl;
		
		std::cout << CYAN << "Attempting to sign form:" << RESET << std::endl;
		charlie.signForm(robot);
		std::cout << GREEN << robot << RESET << std::endl;
		
		std::cout << MAGENTA << "Attempting execution with insufficient grade:" << RESET << std::endl;
		charlie.executeForm(robot); // Should fail
		std::cout << MAGENTA << "Attempting execution with sufficient grade:" << RESET << std::endl;
		diana.executeForm(robot); // Should succeed
		
		std::cout << WHITE << "Testing randomness with multiple executions:" << RESET << std::endl;
		diana.executeForm(robot);
		diana.executeForm(robot);
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BOLD << MAGENTA << "\n=== Testing PresidentialPardonForm ===" << RESET << std::endl;
	try
	{
		Bureaucrat eve("Eve", 20);
		Bureaucrat frank("Frank", 3);
		PresidentialPardonForm pardon("criminal");
		
		std::cout << BLUE << eve << RESET << std::endl;
		std::cout << YELLOW << pardon << RESET << std::endl;
		
		std::cout << CYAN << "Attempting to sign form:" << RESET << std::endl;
		eve.signForm(pardon);
		std::cout << GREEN << pardon << RESET << std::endl;
		
		std::cout << MAGENTA << "Attempting execution with insufficient grade:" << RESET << std::endl;
		eve.executeForm(pardon); // Should fail
		std::cout << MAGENTA << "Attempting execution with sufficient grade:" << RESET << std::endl;
		frank.executeForm(pardon); // Should succeed
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BOLD << RED << "\n=== Testing Exception Cases ===" << RESET << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 150);
		ShrubberyCreationForm unsignedForm("test");
		
		std::cout << CYAN << "Attempting to execute unsigned form:" << RESET << std::endl;
		lowGrade.executeForm(unsignedForm);
		
		std::cout << CYAN << "Attempting to sign with insufficient grade:" << RESET << std::endl;
		lowGrade.signForm(unsignedForm);
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BOLD << WHITE << "\n=== Testing Copy Constructor and Assignment ===" << RESET << std::endl;
	try
	{
		ShrubberyCreationForm original("original");
		ShrubberyCreationForm copy(original);
		ShrubberyCreationForm assigned("temp");
		
		assigned = original;
		
		std::cout << YELLOW << "Original: " << RESET << original << std::endl;
		std::cout << BLUE << "Copy: " << RESET << copy << std::endl;
		std::cout << MAGENTA << "Assigned: " << RESET << assigned << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << BOLD << CYAN << "\n=== End of testing ===" << RESET << std::endl;
	return 0;
}
