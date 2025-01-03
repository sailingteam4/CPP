/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:01:22 by nrontey           #+#    #+#             */
/*   Updated: 2024/12/26 19:08:29 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class Phonebook
{
	private:
		Contact		_contacts[8];
		int			_current_index;
		
		static std::string SpaceAdder(int n);
		static std::string FixMaxLength(std::string str, long unsigned int max);
		static void DisplayContact(Contact contact);
		static int SearchContactIndex(Contact contacts[8]);
		Contact getContact(int index) const;

	public:
		Phonebook();
		~Phonebook();

		void AddContact(void);
		void SearchContact(void);
};

#endif