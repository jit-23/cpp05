#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), signature(false), grade_to_sign(150), grade_to_execute(150) 
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_execute) : name(_name),signature(false),grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute)
{
	std::cout << "Default Form constructor called" << std::endl;
	std::string err_msg;
	std::string buffer;
	std::stringstream out;
	
	/* try catch for value of execution */
	try
    {
		if (_grade_to_execute < 1 || _grade_to_execute > 150)
		{
			out << _grade_to_execute;			
			std::string buffer = " "	 + out.str();
			err_msg = buffer + "is an invalid grade of execution for " + this->GetFormName();
			if (_grade_to_execute < 1){
				err_msg += std::string(" to High for initialization of designed Form!");
				throw(GradeTooHighException(err_msg));
			}
			err_msg += std::string(" to Low for initialization of designed Form!");
			throw(GradeTooLowException(err_msg));
		}
	}
	catch(const std::exception& e){ std::cerr << e.what() << std::endl;}
	/* try catch for value of sign */
	try
    {
		if (_grade_to_sign < 1 || _grade_to_sign > 150)
		{
			out << _grade_to_sign;			
			std::string buffer = " "	 + out.str();
			err_msg = buffer + "is an invalid grade of signing for " + this->GetFormName();
			if (_grade_to_sign < 1){
				err_msg += std::string(" to High for initialization of designed Form!");
				throw(GradeTooHighException(err_msg));
			}
			err_msg += std::string(" to Low for initialization of designed Form!");
			throw(GradeTooLowException(err_msg));
		}
	}
	catch(const std::exception& e){ std::cerr << e.what() << std::endl;}	
}

/* 
void Form::GradeTooHighException()
{
	if ((this->GetGradeToExecute() > 150 || this->GetGradeToExecute() < 1))
    	std::cout << "Grade " << this->GetGradeToExecute() << " is too high for the Form !\nGrade to execute allowed between 1 and 150" << std::endl;
	if ((this->GetGradeToSign() > 150 || this->GetGradeToSign() < 1))
    	std::cout << "Grade " << this->GetGradeToSign() << " is too high for the Form !\nGrade to sign allowed between 1 and 150" << std::endl;
}


void  Form::GradeTooLowException()
{
	if ((this->GetGradeToExecute() > 150 || this->GetGradeToExecute() < 1))
    	std::cout << "Grade " << this->GetGradeToExecute() << " is too low for the Form !\nGrade to execute allowed between 1 and 150" << std::endl;
	if ((this->GetGradeToSign() > 150 || this->GetGradeToSign() < 1))
    	std::cout << "Grade " << this->GetGradeToSign() << " is too low for the Form !\nGrade to sign allowed between 1 and 150" << std::endl;
} */

Form::Form(const Form &other) : name(other.name), signature(other.signature)  , grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{	
	std::cout << "Form Copy constructor called!" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade_to_sign = other.grade_to_sign; 
		this->grade_to_execute = other.grade_to_execute; 
		this->signature = other.signature;
	}
	return *this;
}

/* Getters */

int 		Form::GetGradeToExecute()const{return this->grade_to_execute;}
int 		Form::GetGradeToSign()const{return this->grade_to_sign;}
std::string Form::GetFormName() const{return (this->name);}

std::string Form::GetFormSignature()const{
	if (this->signature)
		return ("Form Signed");
	return ("Form not Signed");
}

Form::~Form()
{
	std::cout << "Default Form destructor called" << std::endl;
}


std::ostream &operator<<(std::ostream &_cout, Form const  &other)
{
	_cout << "Form: " << other.GetFormName()  << std::endl;
	_cout << "Signature situation:" << other.GetFormSignature() <<  std::endl;
	_cout << "Grade neccessary for signing : " << other.GetGradeToSign() <<  std::endl;
	_cout << "Grade neccessary for execution : " << other.GetGradeToExecute() <<  std::endl;
	return (_cout);
}
