#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Intern
{
private:

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();
    AForm* makeForm(const std::string form_name, const std::string _target);
};
    AForm* CreateShrubberyForm(std::string _target);
    AForm* CreateRobotForm(std::string _target);
    AForm* CreatePresidentialForm(std::string _target);
#endif
