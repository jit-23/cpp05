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
        
        class GradeTooHighException : public std::exception {
    		private:
				std::string message;
			public:
				GradeTooHighException(const std::string &msg) : message(msg){} // 
				virtual const char* what() const throw() { return (message.c_str());}
				~GradeTooHighException()  throw(){} // 

    	};
    	class GradeTooLowException : public std::exception { // define the especific mesage on the .cpp file when using try and catch 
			private:
				std::string message;
			public:
				GradeTooLowException(const std::string &msg) : message(msg){} // constructor for exception class
				virtual const char* what() const throw()  { return (message.c_str());}
				~GradeTooLowException()  throw(){} // 
		};
			void incremment_grade();
			void decremment_grade();
	~Bureaucrat();
	
	std::ostream&  operator<<(std::ostream &_cout,  Bureaucrat const &other);
	#endif

	/* int main() {
    try {
        throw MyException("File not found: config.txt");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
} */