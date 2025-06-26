#ifndef BUREAUCRAT 
#define BUREAUCRAT

#include <iostream>
#include <ostream>
#include <cstring>
#include <cctype>

#include<exception> // basics of exception classes
#include<stdexcept> // exception ++ (way more standard exception classes )


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
        
        class GradeTooHighException : public std::exception {
    		private:
				std::string message;
			public:
				GradeTooHighException(const std::string &msg) : message(msg){} // 
	        	const char* what() const noexcept override { return (message.c_str());}
    	};
    	class GradeTooLowException : public std::exception { // define the especific mesage on the .cpp file when using try and catch 
			private:
				std::string message;
			public:
				GradeTooLowException(const std::string &msg) : message(msg){} // constructor for exception class
    	    	const char* what() const noexcept override { return (message.c_str());}
    	};
		void incremment_grade();
		void decremment_grade();
	};
	
	std::ostream&  operator<<(std::ostream &_cout,  Bureaucrat const &other);
/* 
	void Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade " << this->getGrade() << " is too high for the bureaucraf!\nGrades allowed between 1 and 150" << std::endl;
}

void Bureaucrat::GradeTooLowException()
{
    std::cout << "Grade " << this->getGrade() << " is too low for the bureaucraf!\nGrades allowed between 1 and 150" << std::endl;
} */
#endif