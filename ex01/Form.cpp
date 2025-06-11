#include "Form.hpp"

Form::Form() : name("Form"), signature(false), grade_to_sign(150), grade_to_execute(150) 
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_execute) : name(_name), grade_to_sign(_grade_to_sign), grade_to_execute(grade_to_execute), signature(false)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(Form &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute), signature(other.signature)  
{
	if (other)
}

Form::~Form()
{
	std::cout << "Default Form destructor called" << std::endl;
}