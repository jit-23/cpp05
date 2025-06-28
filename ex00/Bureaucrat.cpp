#include "Bureaucrat.hpp"


std::ostream &operator<<(std::ostream &_cout,  Bureaucrat const &other);


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

#include <sstream> // library that allows concatenation, insertion and extration from strings. (it allows big performance from std::strings)

/* only grade passed */
Bureaucrat::Bureaucrat(int _grade) : grade(_grade)
{
	std::cout << "Bureaucrat default Constructor called" << std::endl;
	this->name = "Bureaucrat";
	std::stringstream out;
	out << _grade;
	std::string buffer = " "	 + out.str();
	std::string err_msg = "Invalid grade for " + this->getName();
	err_msg += buffer;
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
	catch(const std::exception& e){ std::cerr << e.what() << std::endl;}
	
}

/* both args(name and grade) passed */
Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade)
{
	std::cout << "Bureaucrat default Constructor called" << std::endl;
	std::stringstream out;
	out << _grade;
	std::string buffer = " "	 + out.str();
	std::string err_msg = "Invalid grade for " + this->getName();
	err_msg += buffer;

	try
	{
		if (_grade > 150)
		{
			err_msg =  err_msg + std::string(" is to Low") + std::string("!!");
			this->grade = 150;
			throw GradeTooLowException(err_msg);
		}
		if (_grade < 1)
		{
			err_msg =  err_msg + std::string(" is to High") + std::string("!!");
            throw GradeTooHighException(err_msg);
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	
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

//void Bureaucrat::GradeTooHighException()
//{
//	std::cout << "Grade " << this->getGrade() << " is too high for the bureaucraf!\nGrades allowed between 1 and 150" << std::endl;
//}
//
//void Bureaucrat::GradeTooLowException()
//{
//    std::cout << "Grade " << this->getGrade() << " is too low for the bureaucraf!\nGrades allowed between 1 and 150" << std::endl;
//}

Bureaucrat::~Bureaucrat()
{
std::cout << "Bureaucrat Destructor called" << std::endl;
}

void Bureaucrat::incremment_grade()
{
	if (this->grade - 1 == 0)
	{
		std::cout << "Can't increment more than 1!" <<  std::endl;
		return;
	}
	this->grade--;

}

void	Bureaucrat::decremment_grade()
{
	if (this->grade + 1 == 151)
	{
		std::cout << "Can't decrement more than 150!" <<  std::endl;
		return;
	}
	this->grade++;
}

std::ostream &operator<<(std::ostream  &_cout, const Bureaucrat &other)
{
	_cout << other.getName() << ", bureaucrat grade " << other.getGrade()/*  <<  std::endl */;
	return (_cout);
}
