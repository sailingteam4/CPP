#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;  // Forward declaration

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

        void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;

        class FileOpenException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif
