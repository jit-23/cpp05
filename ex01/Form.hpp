#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool signature;
		const int grade_to_sign;
		const int grade_to_execute;
	public:
		Form();
		Form(std::string _name, int _grade_to_sign, int _grade_to_execute);
		Form(const Form &other);

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
		
		bool BeSigned( const Bureaucrat  &other);
		std::string GetFormSignature_str()const;
		bool GetFormSignature_bool()const;
		std::string GetFormName()const;
		int GetGradeToSign()const;
		int GetGradeToExecute()const;
		Form& operator=(const Form &other);
		~Form();
	};
	
	std::ostream &operator<<(std::ostream &_cout, const Form   &other);



#endif
