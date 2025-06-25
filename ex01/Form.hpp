#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string name;
		bool signature;
		int grade_to_sign;
		int grade_to_execute;
	public:
		Form();
		Form(std::string _name, int _grade_to_sign, int _grade_to_execute);
		Form(const Form &other);
		void GradeTooHighException();
		void GradeTooLowException();

		void BeSigned(Bureaucrat const &other);

		std::string GetFormSignature()const;
		std::string GetFormName()const;
		int GetGradeToSign()const;
		int GetGradeToExecute()const;
		Form& operator=(const Form &other);
		~Form();
	};
	
	std::ostream &operator<<(std::ostream &_cout, Form const  &other);



#endif
