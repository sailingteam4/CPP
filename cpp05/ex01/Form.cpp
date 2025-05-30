#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unknown Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

Form::Form(const Form& other) 
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
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

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void Form::validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high (must be >= 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", signed: " << (form.getSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign() 
	   << ", grade to execute: " << form.getGradeToExecute() << ".";
	return os;
}
