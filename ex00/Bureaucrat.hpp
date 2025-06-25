#ifndef BUREAUCRAT 
#define BUREAUCRAT

#include <iostream>
#include <ostream>
#include <cstring>
#include <cctype>
#include <exception>

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

void Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade " << this->getGrade() << " is too high for the bureaucraf!\nGrades allowed between 1 and 150" << std::endl;
}

void Bureaucrat::GradeTooLowException()
{
    std::cout << "Grade " << this->getGrade() << " is too low for the bureaucraf!\nGrades allowed between 1 and 150" << std::endl;
}

#endif