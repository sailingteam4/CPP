/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:29:33 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/30 14:42:19 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form " << _name << " constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    _signed = false;
}

Form::Form() : _name("default"), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "Form default constructor called" << std::endl;
    _signed = false;
}

Form::Form(Form const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Form " << _name << " copy constructor called" << std::endl;
    _signed = src._signed;
}

Form::~Form()
{
    std::cout << "Form " << _name << " destructor called" << std::endl;
}

Form & Form::operator=(Form const & src)
{
    std::cout << "Form " << _name << " assignation operator called" << std::endl;
    if (this != &src)
    {
        _signed = src._signed;
    }
    return *this;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat & src)
{
    if (src.getGrade() >= _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream & operator<<(std::ostream & os, Form const & src)
{
    os << "Form " << src.getName() << " is ";
    if (src.getSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << src.getGradeToSign() << " to sign and grade " << src.getGradeToExecute() << " to execute";
    return os;
}
