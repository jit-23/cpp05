#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		const std::string target;
		bool signature;
		const int grade_to_sign;
		const int grade_to_execute;
	public:
		AForm();
		AForm(std::string _name, std::string _target,  int _grade_to_sign, int _grade_to_execute);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);

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
		
		void execute(Bureaucrat const & executor) const ;
		virtual void execute_it()const  = 0;
		/* virtual */ bool BeSigned( const Bureaucrat  &other);
	
		std::string GetFormSignature_str()const;
		bool GetFormSignature_bool()const;
		std::string GetFormName()const;
		int GetGradeToSign()const;
		int GetGradeToExecute()const;

		/* SETTER */
		void SetTarget(const std::string _target);

		void SetFormSignature(bool _bool);
		
		/* EX02 */
		std::string GetTarget()const;
		
		virtual ~AForm();
	};
	
	std::ostream &operator<<(std::ostream &_cout, const AForm   &other);


#endif
