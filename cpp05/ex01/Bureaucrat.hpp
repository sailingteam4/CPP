/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:24:15 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/12 00:47:47 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat();
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat();

        Bureaucrat&                 operator=(Bureaucrat const & src);

        std::string                 getName() const;
        int                         getGrade() const;

        void                        promote();
        void                        unmote();
        void                        signForm(Form& Form) const;

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

    private:
        std::string const           _name;
        int                         _grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & src);

#endif