#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void explain_color_scheme(){

	std::cout << GREEN << "GREEN" << END << ":Constructors;"<< std::endl;
	std::cout << BLUE << "BLUE" << END << ":operator Overload;"<< std::endl;
	std::cout << RED << "RED" << END << ":Destructor;"<< std::endl;
	std::cout << ORANGE << "ORANGE" << END << ":ERR_MSG of try/catch;"<< std::endl;
}

int main()
{
	
	Intern someRandomIntern;
	try
	{
		AForm* rrf1;
		rrf1 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		std::cout << *rrf1 << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << END << '\n';
	}

	/* 1 */

	try
	{
		AForm* rrf2;
		rrf2 = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		std::cout << *rrf2 << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << END << '\n';
	}
	/*  2 */
	try
	{
		AForm* rrf2;
		rrf2 = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		std::cout << *rrf2 << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << END << '\n';
	}
	/* 3 */
	try
	{
		AForm* rrf2;
		rrf2 = someRandomIntern.makeForm("andsdndanadn", "Bender");
		std::cout << *rrf2 << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << END << '\n';
	}
	/*  */ 
	return 0;
	}

/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed */