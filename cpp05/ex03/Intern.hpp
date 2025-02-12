/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:20:00 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/12 00:26:35 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    private:
        AForm* createShrubberyForm(std::string target);
        AForm* createRobotomyForm(std::string target);
        AForm* createPresidentialForm(std::string target);

    public:
        Intern();
        Intern(const Intern& src);
        ~Intern();
        
        Intern& operator=(const Intern& src);
        
        AForm* makeForm(std::string formName, std::string target);
        
        class FormNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif
