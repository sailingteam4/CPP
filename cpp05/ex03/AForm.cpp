/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:29:33 by nrontey           #+#    #+#             */
/*   Updated: 2025/02/04 16:58:38 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm " << _name << " constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    _signed = false;
}

AForm::AForm() : _name("default"), _gradeToSign(1), _gradeToExecute(1)
{
    std::cout << "AForm default constructor called" << std::endl;
    _signed = false;
}

AForm::AForm(AForm const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm " << _name << " copy constructor called" << std::endl;
    _signed = src._signed;
}

AForm::~AForm()
{
    std::cout << "AForm " << _name << " destructor called" << std::endl;
}

AForm & AForm::operator=(AForm const & src)
{
    std::cout << "AForm " << _name << " assignation operator called" << std::endl;
    if (this != &src)
    {
        _signed = src._signed;
    }
    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat & src)
{
    if (src.getGrade() >= _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream & operator<<(std::ostream & os, AForm const & src)
{
    os << "AForm " << src.getName() << " is ";
    if (src.getSigned())
        os << "signed";
    else
        os << "not signed";
    os << " and requires grade " << src.getGradeToSign() << " to sign and grade " << src.getGradeToExecute() << " to execute";
    return os;
}
