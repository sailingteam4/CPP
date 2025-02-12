#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"  // Add this include

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
    : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
    return _target;
}
