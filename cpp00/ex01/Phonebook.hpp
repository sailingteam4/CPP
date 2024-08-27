/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:01:22 by nrontey           #+#    #+#             */
/*   Updated: 2024/08/22 03:21:48 by nrontey          ###   ########.fr       */
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
		Contact _contacts[8];
		int _current_index;
	
	public:
		Phonebook();
		~Phonebook();
		

		// Utils
		std::string SpaceAdder(int n);
		std::string FixMaxLength(std::string str, long unsigned int max);
		int 		SearchContactIndex(Contact contact[8]);

		// Main func
		void 		AddContact(void);
		void 		SearchContact(void);
		void 		DisplayContact(Contact contact);

		Contact 	getContact(int index) const;
};

#endif