#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

void explain_color_scheme(){

	std::cout << GREEN << "GREEN" << END << ":Constructors;"<< std::endl;
	std::cout << BLUE << "BLUE" << END << ":operator Overload;"<< std::endl;
	std::cout << RED << "RED" << END << ":Destructor;"<< std::endl;
	std::cout << ORANGE << "ORANGE" << END << ":ERR_MSG of try/catch;"<< std::endl;
}

int main()
{
	{
		
		Bureaucrat b1("this guy", 2);
		ShrubberyCreationForm S("FORM1!");
		std::cout << S << std::endl; 
		std::cout << S.GetTarget() << std::endl; 
		S.execute(b1);
		/* code */
	}
	{
		
		Bureaucrat b1("this guy", 2);
		RobotomyRequestForm S("FORM2!");
		std::cout << S << std::endl; 
		std::cout << S.GetTarget() << std::endl; 
		S.execute(b1);
		/* code */
	}
	{
		
		Bureaucrat b1("this guy", 2);
		PresidentialPardonForm S("FORM3!");
		std::cout << S << std::endl; 
		std::cout << S.GetTarget() << std::endl; 
		S.execute(b1);
		/* code */
	}
	return 0;
}

/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed */