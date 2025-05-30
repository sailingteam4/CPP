#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(const Bureaucrat& bureaucrat);

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
		void				validateGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
