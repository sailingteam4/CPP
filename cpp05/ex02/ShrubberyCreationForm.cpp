#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeForm() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

	file << "               ,@@@@@@@,\n";
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	file << "       |o|        | |         | |\n";
	file << "       |.|        | |         | |\n";
	file << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n\n";

	file << "                 ___\n";
	file << "         _,-'\"\"   \"\"\"`.        \n";
	file << "       ,'  _   _   _  \\       \n";
	file << "      /  (_) (_) (_)   \\      \n";
	file << "     /                  \\     \n";
	file << "    /    ,-..-\"-.-.     \\    \n";
	file << "   /    /           \\     \\   \n";
	file << "  /    /  ,-.   ,-.  \\     \\  \n";
	file << " /    /  (_)     (_)  \\     \\ \n";
	file << "/    /               \\     \\\n";
	file << "\\    \\               /     /\n";
	file << " \\    \\  ,-.   ,-.  /     / \n";
	file << "  \\    \\(_)     (_)/     /  \n";
	file << "   \\    \\           /     /   \n";
	file << "    \\    `-....-'      /    \n";
	file << "     \\                 /     \n";
	file << "      \\  (_) (_) (_)   /      \n";
	file << "       `,             ,'       \n";
	file << "         `-..._..._,-'         \n";

	file.close();
	std::cout << "Shrubbery has been planted at " << _target << std::endl;
}
