#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "the presindent", 72, 45 )
{
    std::cout << " RobotomyRequestForm Default constructor called!" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", _target, 137, 145)
{
    std::cout << " RobotomyRequestForm Default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :  AForm(other)
{
    std::cout << " RobotomyRequestForm copy constructor called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other ) {
    if (this != &other)
		this->SetFormSignature(other.GetFormSignature_bool());
    return (*this);
}

void RobotomyRequestForm::execute_it(){
    
}


/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox */