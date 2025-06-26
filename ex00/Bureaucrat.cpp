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
	this->name = "Bureaucrat";
	std::string grade_str = " " + itoa(_grade);
	std::string err_msg = "Invalid grade for " + this->getName();
	err_msg += grade_str;
	
	try
	{
		if (_grade > 150)
		{
			err_msg += " is to Low for creation!!";
            throw GradeTooLowException(err_msg);
		}
		if (_grade < 1)
		{
			err_msg += " is to High for creation!!";
            throw GradeTooHighException(err_msg);
		}
	}
	catch(const std::exception& e)
		std::cerr << e.what() << std::endl;
	
    std::cout << "Bureaucrat default Constructor called" << std::endl;
}

/* both args(name and grade) passed */
Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade)
{
	std::string grade_str = " " + itoa(_grade);
	std::string err_msg = "Invalid grade for " + this->getName();
	err_msg += grade_str;
	
	try
	{
		if (_grade > 150)
		{
			err_msg += " is to Low for creation!!";
            throw GradeTooLowException(err_msg);
		}
		if (_grade < 1)
		{
			err_msg += " is to High for creation!!";
            throw GradeTooHighException(err_msg);
		}
	}
	catch(const std::exception& e)
		std::cerr << e.what() << std::endl;
	
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
	this->grade--;
}

void Bureaucrat::decremment_grade()
{
	this->grade++;
}

std::ostream& operator<<(std::ostream &_cout, Bureaucrat const  &other)
{
	_cout << other.getName() << ", bureaucrat grade " << other.getGrade() <<  std::endl;
	return (_cout);
}
