#include "Bureaucrat.hpp"

/* nothing passed */
Bureaucrat::Bureaucrat(void) : name("bureaucrat"), grade(150)
{
    std::cout << "Bureaucrat default Constructor called" << std::endl;
}

/* only name passed */
Bureaucrat::Bureaucrat(const std::string _name) : name(_name)
{
    grade = 150;
    std::cout << "Bureaucrat default Constructor called" << std::endl;
}

/* only grade passed */
Bureaucrat::Bureaucrat(int _grade) : grade(_grade)
{
    try
    {
        if (_grade > 150 || _grade < 1)
            throw _grade;       
        this->grade = _grade;
    }
    catch(int e)
    {
        if (e > 150)
            GradeTooHighException();
        else
            GradeTooLowException(); 
    }
    
    this->name = "Bureaucrat";
    std::cout << "Bureaucrat default Constructor called" << std::endl;
}

/* both args(name and grade) passed */
Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade)
{
    name = "Bureaucrat";
    std::cout << "Bureaucrat default Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        name = other.getName();
        grade = other.getGrade();
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

void Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade " << this->getGrade() << " is too high for the bureaucraf!\nGrades allowed between 1 and 150" << std::endl;
}

void Bureaucrat::GradeTooLowException()
{
    std::cout << "Grade " << this->getGrade() << " is too low for the bureaucraf!\nGrades allowed between 1 and 150" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

void Bureaucrat::incremment_grade()
{
	this->grade++;
}

void Bureaucrat::decremment_grade()
{
	this->grade--;
}

std::ostream& operator<<(std::ostream &_cout, Bureaucrat const  &other)
{
	_cout << other.getName() << ", bureaucrat grade " << other.getGrade() <<  std::endl;
	return (_cout);
}
