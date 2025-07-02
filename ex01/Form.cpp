#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("your_Form"), signature(false), grade_to_sign(150), grade_to_execute(150)  {std::cout<<GREEN << "Default Form constructor called"<<END<< std::endl;}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_execute) : name(_name),signature(false),grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute)
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


Form::Form(const Form &other) : name(other.name), signature(other.signature)  , grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute){	
std::cout << GREEN<< "Form Copy constructor called!"<<END << std::endl;}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->signature = other.signature;
	// the only modifiable var is the sigture, bcs   the rest are const;
	return *this;
}

/* Getters */

int 		Form::GetGradeToExecute()const{return this->grade_to_execute;}
int 		Form::GetGradeToSign()const{return this->grade_to_sign;}
std::string Form::GetFormName() const{return (this->name);}

std::string Form::GetFormSignature_str()const{
	if (this->signature)
		return ("Form Signed");
	return ("Form not Signed");
}

bool Form::GetFormSignature_bool()const{ return this->signature;}

std::ostream &operator<<(std::ostream &_cout, const Form   &other)
{
	std::string color;
	if (other.GetFormSignature_bool())
		color = GREEN;
	else
		color = RED;
	_cout << "Form: " << other.GetFormName()  << std::endl;
	_cout << "Signature situation: "<< color << other.GetFormSignature_str() << BLUE <<std::endl;
	_cout << "Grade neccessary for signing : " << other.GetGradeToSign() <<  std::endl;
	_cout << "Grade neccessary for execution : " << other.GetGradeToExecute() <<  std::endl;
	return (_cout);
}


bool Form::BeSigned( const Bureaucrat &other){
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


Form::~Form() {std::cout << RED << "Default Form destructor called" << END <<std::endl;}

/* Now that you have bureaucrats, let’s give them something to do. What better activity
could there be than filling out a stack of forms?
Let’s create a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it is not).
• A constant grade required to sign it.
• A constant grade required to execute it.
All these attributes are private, not protected.
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
As before, write getters for all attributes and overload the insertion («) operator to
print all the form’s information.
8
C++ - Module 05 Repetition and Exceptions
//============================================//
Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
(greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
// aplicar msg de error  em besigned, i aplicar msg de assinatura posictiva no signform 
Then, modify the signForm() member function in the Bureaucrat class. This func-
tion must call Form::beSigned() to attempt to sign the form. If the form is signed
successfully, it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
Implement and submit some tests to ensure everything works as expected. */