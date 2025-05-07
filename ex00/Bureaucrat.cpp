#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("bureaucrat"), grade(150)
{
    std::cout << "Bureaucrat default Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        name = other.getName();
        name = other.getName();
    }
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)// : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy Constructor called" << std::endl;
    *this = other;
}

int Bureaucrat::getGrade()const{
    return this->grade;
}

std::string  Bureaucrat::getName() const{
    return this->name;
}

