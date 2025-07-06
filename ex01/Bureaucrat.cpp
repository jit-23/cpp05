#include "Bureaucrat.hpp"
#include "Form.hpp"
class Form;
/* nothing passed */
Bureaucrat::Bureaucrat(void) : name("bureaucrat"), grade(150)
{
    std::cout << GREEN << "Bureaucrat default Constructor called"<< END << std::endl;
}

/* only name passed */
Bureaucrat::Bureaucrat(const std::string _name) : name(_name)
{
    grade = 150;
    std::cout << GREEN<< "Bureaucrat default Constructor called" << END<<std::endl;
}


/* only grade passed */
Bureaucrat::Bureaucrat(int _grade) : name("Bureaucrat"),  grade(_grade) 
{
	std::cout << GREEN <<"Bureaucrat default Constructor called" << END<<std::endl;
	std::stringstream out;
	out << _grade;
	std::string buffer = " " + out.str();
	std::string err_msg = "Invalid grade for " + this->getName();
	err_msg += buffer;
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
	

/* both args(name and grade) passed */
Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade)
{
	std::cout << GREEN<<"Bureaucrat default Constructor called" << END<<std::endl;
	std::stringstream out;
	out << _grade;
	std::string buffer = " "	 + out.str();
	std::string err_msg = "Invalid grade for " + this->getName();
	err_msg += buffer;
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
	//	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        grade = other.getGrade();
       // name is a const var, cant assign it. so grade will be the only thing being copied
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) { std::cout <<GREEN<< "Bureaucrat copy Constructor called" << END<< 	std::endl;}

int Bureaucrat::getGrade()const{ return this->grade;}

std::string  Bureaucrat::getName() const{ return this->name;}


Bureaucrat::~Bureaucrat() { std::cout  << RED << "Bureaucrat Destructor called" << END <<  std::endl;}
void Bureaucrat::incremment_grade()
{
	if (this->grade - 1 <= 0)
		throw(GradeTooHighException("Can't incremment more than 1!"));
	this->grade--;
}

void	Bureaucrat::decremment_grade()
{
	if (this->grade + 1  >= 151)
		throw(GradeTooHighException("Can't decremment less than 150!"));
	this->grade++;
}

void Bureaucrat::signForm(Form &form){
	if (form.BeSigned(*this))
		std::cout << /* GREEN << */ this->getName() << " signed " << form.GetFormName() << END << std::endl;
	// if be signed is not posible the throw inside of besigned is activated, so there is no need for else statemment here	
	
	//else
		/* std::cout << this->getName() << " couldn't sign " << form.GetFormName() << " because their mom didn't let them :("<< std::endl; */
}

std::ostream &operator<<(std::ostream  &_cout, const Bureaucrat &other)
{
	_cout << other.getName() << ", bureaucrat grade " << other.getGrade()/*  <<  std::endl */;
	return (_cout);
}
