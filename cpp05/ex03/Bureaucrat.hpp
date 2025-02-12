/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:24:15 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/11 23:14:19 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

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
        void                        signAForm(AForm& AForm) const;
        void                        executeAForm(AForm const & form) const;
        void                        executeForm(AForm const & form) const;

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