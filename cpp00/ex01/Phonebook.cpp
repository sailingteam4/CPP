/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:04:34 by nrontey           #+#    #+#             */
/*   Updated: 2024/08/27 00:43:17 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

Phonebook::Phonebook()
{
	this->_current_index = 0;
	std::cout << "Welcome to this awesome Phonebook. Empty Phonebook with 8 contact slot created" << std::endl;
	return;
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook destroyed goodbye" << std::endl;
	return;
}

void	Phonebook::AddContact(void)
{
	std::string str;

	str = "";
	if (this->_current_index > 7)
	{
		std::cout << "[INFO] Overwriting contact : " << this->_contacts[this->_current_index % 8].getFirstName() << std::endl;
	}
	
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter first name: ";
		if (std::getline(std::cin, str))
			this->_contacts[this->_current_index % 8].setFirstName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_current_index % 8].getFirstName() << "'s last name: ";
		if (std::getline(std::cin, str))
			this->_contacts[this->_current_index % 8].setLastName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_current_index % 8].getFirstName() << "'s nickname: ";
		if (std::getline(std::cin, str))
			this->_contacts[this->_current_index % 8].setNickname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "enter " << this->_contacts[this->_current_index % 8].getFirstName() << "'s phone number: ";
		if (std::getline(std::cin, str))
			this->_contacts[this->_current_index % 8].setPhoneNumber(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_current_index % 8].getFirstName() << "'s darkest secret: ";
		if (std::getline(std::cin, str))
		{
			this->_contacts[this->_current_index % 8].setDarkestSecret(str);
			std::cout << this->_contacts[this->_current_index % 8].getFirstName() << " added to phonebook on slot " << this->_current_index % 8 << "/8" << std::endl;
		}
	}
	this->_current_index++;
};

void	Phonebook::DisplayContact(Contact contact)
{
	std::cout << "Asking the magic server for the information ..." << std::endl;
	if (contact.getFirstName().empty())
	{
		std::cout << "This contact does not exist" << std::endl;
		return;
	}
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
};

Contact	Phonebook::getContact(int index) const
{
	return (this->_contacts[index % 8]);
};

std::string Phonebook::SpaceAdder(int n)
{
	std::string str;

	while (n--)
		str.append(" ");
	return (str);
	
};

std::string Phonebook::FixMaxLength(std::string str, long unsigned int max)
{
	if (str.length() > max)
	{
		str.resize(max);
		str[max - 1] = '.';
	}
	return (str);	
};

int	Phonebook::SearchContactIndex(Contact contact[8])
{
	char		c;
	int			i;
	std::string	str;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "| Index|First Name| Last Name|  Nickname |" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	i = 0;
	c = '0';
};