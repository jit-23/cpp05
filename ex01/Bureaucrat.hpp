#ifndef BUREAUCRAT 
#define BUREAUCRAT

#include <iostream>
#include <ostream>
#include <cstring>
#include <cctype>


class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        
        Bureaucrat();
        Bureaucrat(int _grade);
        Bureaucrat(const std::string _name);
        Bureaucrat(const std::string _name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat&  operator=(const Bureaucrat &other);
        
        int getGrade()const;
        std::string getName()const;
        ~Bureaucrat();
        
        void GradeTooHighException(); 
        void GradeTooLowException();
		
		void incremment_grade();
		void decremment_grade();
	};
	
	std::ostream&  operator<<(std::ostream &_cout,  Bureaucrat const &other);

#endif