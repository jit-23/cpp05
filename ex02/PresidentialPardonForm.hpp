#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP




#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    
    std::string target;
/*
bool signature;
    const std::string form_name;
    const int grade_to_sign;
    const int grade_to_execute; */

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

    /* virtual functions */
    /* virtual *//*  bool BeSigned(const Bureaucrat &other); */
 
    void execute_it()const ;    
    


    /* SETTERS */         

    /*  */

    ~PresidentialPardonForm();


};

#endif