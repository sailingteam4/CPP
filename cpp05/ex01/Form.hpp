/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:29:32 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/12 00:47:31 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form();
		Form(Form const & src);
		~Form();

		Form & operator=(Form const & src);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void		beSigned(const Bureaucrat & src);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & os, Form const & src);

#endif