#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;

    public:
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

        void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;
};

#endif
