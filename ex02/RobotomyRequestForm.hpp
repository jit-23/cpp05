#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include  "Bureaucrat.hpp"
#include  "AForm.hpp"


#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
private:
    
    std::string target;
/*
bool signature;
    const std::string form_name;
    const int grade_to_sign;
    const int grade_to_execute; */

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

    /* virtual functions */
    /* virtual *//*  bool BeSigned(const Bureaucrat &other); */
 
    void execute_it()const ;    
    


    /* SETTERS */         

    /*  */

    ~RobotomyRequestForm();


};

#endif