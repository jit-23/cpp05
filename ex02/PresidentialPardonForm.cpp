#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "the presindent", 72, 45 )
{
    std::cout <<GREEN<< "PresidentialPardonForm Default constructor called!" <<END<< std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", _target, 72, 45)
{
    std::cout <<GREEN<< "PresidentialPardonForm Default constructor called!" <<END<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :  AForm(other)
{
    std::cout <<GREEN<< "PresidentialPardonForm copy constructor called!" <<END<< std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other ) {
    if (this != &other)
		this->SetFormSignature(other.GetFormSignature_bool());
    return (*this);
}

void PresidentialPardonForm::execute_it()const{
    
    std::cout << this->GetTarget() << " has been pardoned by !✨Zaphod Beeblebrox✨! "<< END<< std::endl;

}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout <<RED<< "PresidentialPardonForm Default destructor called!" <<END<< std::endl;
}

/* PresidentialPardonForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
• PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox */