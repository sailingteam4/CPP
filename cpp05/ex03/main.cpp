#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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

int main()
{
	std::cout << BOLD << CYAN << "=== Testing Intern Class ===" << RESET << std::endl;

	std::cout << BOLD << GREEN << "\n=== Testing Valid Form Creation ===" << RESET << std::endl;
	
	Intern someRandomIntern;
	Bureaucrat president("President", 1);
	
	{
		std::cout << YELLOW << "Creating RobotomyRequestForm:" << RESET << std::endl;
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << BLUE << *rrf << RESET << std::endl;
			president.signForm(*rrf);
			president.executeForm(*rrf);
			delete rrf;
		}
	}
	
	std::cout << std::endl;
	
	{
		std::cout << YELLOW << "Creating ShrubberyCreationForm:" << RESET << std::endl;
		AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
		if (scf)
		{
			std::cout << BLUE << *scf << RESET << std::endl;
			president.signForm(*scf);
			president.executeForm(*scf);
			delete scf;
		}
	}
	
	std::cout << std::endl;
	
	{
		std::cout << YELLOW << "Creating PresidentialPardonForm:" << RESET << std::endl;
		AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (ppf)
		{
			std::cout << BLUE << *ppf << RESET << std::endl;
			president.signForm(*ppf);
			president.executeForm(*ppf);
			delete ppf;
		}
	}
	
	std::cout << BOLD << RED << "\n=== Testing Invalid Form Names ===" << RESET << std::endl;
	
	{
		std::cout << YELLOW << "Attempting to create invalid form:" << RESET << std::endl;
		AForm* invalid1 = someRandomIntern.makeForm("invalid form", "target");
		if (!invalid1)
			std::cout << GREEN << "Correctly returned NULL for invalid form" << RESET << std::endl;
	}
	
	{
		std::cout << YELLOW << "Attempting to create another invalid form:" << RESET << std::endl;
		AForm* invalid2 = someRandomIntern.makeForm("coffee making", "caffeine");
		if (!invalid2)
			std::cout << GREEN << "Correctly returned NULL for invalid form" << RESET << std::endl;
	}
	
	{
		std::cout << YELLOW << "Attempting to create form with wrong case:" << RESET << std::endl;
		AForm* invalid3 = someRandomIntern.makeForm("Robotomy Request", "target");
		if (!invalid3)
			std::cout << GREEN << "Correctly returned NULL for case-sensitive form name" << RESET << std::endl;
	}
	
	std::cout << BOLD << WHITE << "\n=== Testing Intern Copy and Assignment ===" << RESET << std::endl;
	
	{
		Intern originalIntern;
		Intern copyIntern(originalIntern);
		Intern assignedIntern;
		
		assignedIntern = originalIntern;
		
		std::cout << CYAN << "Testing that all intern instances work the same:" << RESET << std::endl;
		
		AForm* form1 = originalIntern.makeForm("robotomy request", "target1");
		AForm* form2 = copyIntern.makeForm("robotomy request", "target2");
		AForm* form3 = assignedIntern.makeForm("robotomy request", "target3");
		
		if (form1) delete form1;
		if (form2) delete form2;
		if (form3) delete form3;
	}
	
	std::cout << BOLD << CYAN << "\n=== End of testing ===" << RESET << std::endl;
	return 0;
}
