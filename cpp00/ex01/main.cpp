#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main()
{
	Phonebook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phonebook.AddContact();
		else if (command == "SEARCH")
			phonebook.SearchContact();
	}
	return 0;
}