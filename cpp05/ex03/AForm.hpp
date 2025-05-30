#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(const Bureaucrat& bureaucrat);
		void				execute(const Bureaucrat& executor) const;

		virtual void		executeForm() const = 0;

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

		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char* what() const throw();
		};

	private:
		void				validateGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
