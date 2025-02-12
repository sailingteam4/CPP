#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;

    public:
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

        void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;
};

#endif
