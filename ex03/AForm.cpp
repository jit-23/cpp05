
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("your_Form"),  target("random_target"), signature(false), grade_to_sign(150), grade_to_execute(150)  {std::cout<<GREEN << "Default AForm constructor called"<<END<< std::endl;}

AForm::AForm(std::string _name, std::string _target, int _grade_to_sign, int _grade_to_execute) : name(_name), target(_target),signature(false),grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute)
{
	std::cout << GREEN<<"Default Form constructor called" << END<<std::endl;
	std::string err_msg;
	std::string buffer;
	std::stringstream out;
	
	/* try catch for value of execution */ // update, the try catch will be used in the main, here only cosntruct it. 
		if (_grade_to_execute < 1 || _grade_to_execute > 150)
		{
			out << _grade_to_execute;			
			buffer = out.str();
			err_msg = buffer + " is an invalid grade of execution for " + this->GetFormName();
			if (_grade_to_execute < 1){
				err_msg += std::string("! To High for initialization of designed Form!");
				throw(GradeTooHighException(err_msg));
			}
			err_msg += std::string("! To Low for initialization of designed Form!");
			throw(GradeTooLowException(err_msg));
		}
		/* try catch for value of sign */
		if (_grade_to_sign < 1 || _grade_to_sign > 150)
		{
			out << _grade_to_sign;			
			buffer =  out.str();
			err_msg = buffer + " is an invalid grade of signing for " + this->GetFormName();
			if (_grade_to_sign < 1){
				err_msg += std::string("! To High for initialization of designed Form!");
				throw(GradeTooHighException(err_msg));
			}
			err_msg += std::string("! To Low for initialization of designed Form!");
			throw(GradeTooLowException(err_msg));
		}
	}


AForm::AForm(const AForm &other) : name(other.name), target(other.target),  signature(other.signature)  , grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	std::cout << GREEN << "Form Copy constructor called!"<< END << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->signature = other.signature;
	// the only modifiable var is the sigture, bcs   the rest are const;
	return *this;
}

/* Getters */

int 		AForm::GetGradeToExecute()const{return this->grade_to_execute;}
int 		AForm::GetGradeToSign()const{return this->grade_to_sign;}
std::string AForm::GetFormName() const{return (this->name);}
std::string AForm::GetTarget() const{return (this->target);}


std::string AForm::GetFormSignature_str()const{
	if (this->signature)
		return ("Form Signed");
	return ("Form not Signed");
}

bool AForm::GetFormSignature_bool()const{ return this->signature;}

/* Setters */

void AForm::SetFormSignature(bool _bool)
{
	this->signature = _bool;
}


std::ostream &operator<<(std::ostream &_cout, const AForm   &other)
{
	std::string color;
	if (other.GetFormSignature_bool())
		color = GREEN;
	else
		color = RED;
	_cout << BLUE<< "Form: " << other.GetFormName()  << std::endl;
	_cout << "Signature situation: "<< color << other.GetFormSignature_str() << BLUE <<std::endl;
	_cout << "Grade neccessary for signing : " << other.GetGradeToSign() <<  std::endl;
	_cout << "Grade neccessary for execution : " << other.GetGradeToExecute() <<  std::endl;
	return (_cout);
}


bool AForm::BeSigned( const Bureaucrat &other){
	if (this->signature)
	return (false);
	else
	{
		if (other.getGrade() <= this->GetGradeToSign())
		{
			this->signature = true;
			return (true);
		}
			std::string err_msg;
			err_msg = other.getName() + std::string(" couldn't sign ") + this->GetFormName() + std::string(" because the pen is not working :(");
			
			throw(GradeTooLowException(err_msg));
		return (false);
	}
}

/* EX02 functions */

//void AForm::SetTarget(const std::string _target) {this->target = _target;}

void AForm::execute_it() const
{
	std::cout << "overwrite this!!!!!!!!!!!!!!" <<std::endl;
}

void AForm::execute(Bureaucrat const & executor) const
{
	std::string str= this->GetFormName() + std::string(".");
	std::string buffer = std::string("Cant execute ") + str; 


	if (executor.getGrade() > this->GetGradeToExecute())
	{
		throw(GradeTooLowException(buffer));
	}
	execute_it();
	/* std::string file = this->GetTarget() + std::string("_shrubbery");
    
    std::fstream file;
    int fd = open() */
}


AForm::~AForm() {std::cout << RED << "Default AForm destructor called" << END <<std::endl;}
