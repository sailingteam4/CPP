/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:56:28 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/11 23:14:21 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Bureaucrat " << _name << " created" << std::endl;

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat() : _name("default")
{
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
    _grade = 150;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name)
{
    std::cout << "Bureaucrat " << _name << " copy created" << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & src)
{
    std::cout << "Bureaucrat " << _name << " assigned" << std::endl;
    if (this != &src)
        _grade = src._grade;
    return *this;
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade();
    return os;
}

//-----------------------------------------------------------------------------------

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

//-----------------------------------------------------------------------------------

void Bureaucrat::promote()
{
    if (_grade > 1)
        _grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::unmote()
{
    if (_grade < 150)
        _grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signAForm(AForm& AForm) const
{
    try
    {
        AForm.beSigned(*this);
        std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " cannot sign " << AForm.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

//-----------------------------------------------------------------------------------

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high, a bureaucrat cannot have a grade higher than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low, a bureaucrat cannot have a grade lower than 150";
}