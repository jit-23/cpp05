#ifndef BUREAUCRAT 
#define BUREAUCRAT

#include <iostream>
#include <ostream>
#include <cstring>
#include <cctype>
#include <cstdlib> 

#include <sstream> // library that allows concatenation, insertion and extration from strings. (it allows big performance from std::strings)
#include<exception> // basics of exception classes
#include<stdexcept> // exception ++ (way more standard exception classes )

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m" 
#define BLUE  "\033[34m"
#define OLIVE "\033[38;5;3m"
#define PURPLE "\033[38;5;5m"
#define ORANGE "\033[38;5;208m"
#define CYAN "\033[38;5;6m"
#define LIGHT_GRAY "\033[38;5;7m"
#define DARK_GRAY "\033[38;5;8m"
#define END  "\033[0m"

 
//#define RED "\033[0m"   
//#define GREEN "\033[0m" 
//#define YELLOW "\033[0m" 
//#define BLUE "\033[0m"  
//#define END "\033[0m" 
//#define OLIVE "\033[0m" 
//#define PURPLE "\033[0m" 
//#define ORANGE "\033[0m" 
//#define CYAN "\033[0m" 
//#define LIGHT_GRAY "\033[0m" 
//#define DARK_GRAY "\033[0m" 


class AForm;

class Bureaucrat
{
    private:
        const std::string name;
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
		void executeForm(AForm const & form) const;
		void signForm(AForm &form);
		void incremment_grade();
		void decremment_grade();
	~Bureaucrat();
	
};
	std::ostream &operator<<(std::ostream  &_cout,const  Bureaucrat &other);	
	#endif

	/* int main() {
    try {
        throw MyException("File not found: config.txt");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
} */