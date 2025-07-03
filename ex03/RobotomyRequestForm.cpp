#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "the presindent", 72, 45 )
{
    std::cout << "RobotomyRequestForm Default constructor called!" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", _target, 72, 45)
{
    std::cout << "RobotomyRequestForm Default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :  AForm(other)
{
    std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other ) {
    if (this != &other)
		this->SetFormSignature(other.GetFormSignature_bool());
    return (*this);
}

void RobotomyRequestForm::execute_it()const{
    std::srand(std::time(0));
    std::cout << "*DRILLING NOISEEE* #&$*#@&$#@!!" << std::endl;
    int nbr = std::rand() % 2; // generate 1/0 bcs %2 will give the module of 2 of any number

    if (nbr == 1)
        std::cout << this->GetTarget() << " has been robotomized" << std::endl;
    else
        std::cout << this->GetTarget() << " robotomy failed" << std::endl;

}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm Default destructor called!" << std::endl;
}

/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox */