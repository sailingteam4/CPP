#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"  // Add this include

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* DRILLING NOISES *" << std::endl;
    
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }

    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}
