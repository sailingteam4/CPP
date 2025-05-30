#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
	: AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeForm() const
{
	std::cout << "* DRILLING NOISES *" << std::endl;
	std::cout << "BZZZZZZZT... DRRRRRR... BZZZZT..." << std::endl;
	
	static bool seedInitialized = false;
	if (!seedInitialized)
	{
		std::srand(std::time(0));
		seedInitialized = true;
	}
	
	if (std::rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "The robotomy of " << _target << " failed!" << std::endl;
	}
}
