#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw FileOpenException();

    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;

    file.close();
}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Could not open file";
}
