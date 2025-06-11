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
		~Form();
};





#endif
