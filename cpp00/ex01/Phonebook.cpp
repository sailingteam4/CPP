/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:04:34 by nrontey           #+#    #+#             */
/*   Updated: 2024/12/26 19:08:39 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

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
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_current_index % 8].setDarkestSecret(str);
			std::cout << this->_contacts[this->_current_index % 8].getFirstName() 
					 << " added to phonebook on slot " << (this->_current_index % 8) + 1 
					 << "/8" << std::endl;
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
	if (str.length() > max + 1)
	{
		str.resize(max + 1);
		str[max] = '.';
	}
	return (str);
};

int	Phonebook::SearchContactIndex(Contact contacts[8])
{
	int			i;
	std::string	str;
	const int	col_width = 10;
	const char	separator = '|';

	std::cout << separator << std::setfill('-') << std::setw(44) << separator << std::endl;
	std::cout << separator << std::setfill(' ')
			  << std::setw(col_width) << "Index" << separator
			  << std::setw(col_width) << "First Name" << separator
			  << std::setw(col_width) << "Last Name" << separator
			  << std::setw(col_width) << "Nickname" << separator << std::endl;
	std::cout << separator << std::setfill('-') << std::setw(44) << separator << std::endl;
	
	i = 0;
	for (int c = 1; c <= 8; c++)
	{
		if (contacts[c - 1].getFirstName().length())
		{
			i++;
			std::cout << separator << std::setfill(' ')
					  << std::setw(col_width) << c << separator
					  << std::setw(col_width) << FixMaxLength(contacts[c - 1].getFirstName(), 9) << separator
					  << std::setw(col_width) << FixMaxLength(contacts[c - 1].getLastName(), 9) << separator
					  << std::setw(col_width) << FixMaxLength(contacts[c - 1].getNickname(), 9) << separator << std::endl;
		}
	}
	std::cout << separator << std::setfill('-') << std::setw(44) << separator << std::endl;
	return (i);
};

void	Phonebook::SearchContact(void)
{
	std::string	str;
	int valid_contacts = SearchContactIndex(this->_contacts);

	if (!valid_contacts)
	{
		std::cout << "No contact in phonebook" << std::endl;
		return;
	}
	std::cout << "Enter index of the contact you want to display: ";
	while (!std::cin.eof() && std::getline(std::cin, str))
	{
		if (str.length() == 1 && str[0] >= '1' && str[0] <= '8')
		{
			int index = str[0] - '0' - 1;
			if (!this->_contacts[index].getFirstName().empty())
			{
				this->DisplayContact(this->_contacts[index]);
				return;
			}
		}
		std::cout << "Invalid index, please try again: ";
	}
}
