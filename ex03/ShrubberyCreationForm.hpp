#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
    
    std::string target;
/*
bool signature;
    const std::string form_name;
    const int grade_to_sign;
    const int grade_to_execute; */

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

    /* virtual functions */
    /* virtual *//*  bool BeSigned(const Bureaucrat &other); */
 
    void execute_it()const ;    
    


    /* SETTERS */         
    void SetTarget(const std::string _target);

    /*  */

    ~ShrubberyCreationForm();


};

    std::string get_tree();

#endif