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
	AForm* rrf1 = NULL;
	AForm* rrf2 = NULL;
	AForm* rrf3 = NULL;
	AForm* rrf4 = NULL;
	try
	{
		rrf1 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		std::cout << *rrf1 << std::endl;
		Bureaucrat b1("DUDE1", 2);
		b1.executeForm(*rrf1);
		//delete rrf1;
	}
	catch(const std::exception& e)
	{
		//delete rrf1;
		std::cerr << ORANGE << e.what() << END << '\n';
	}

	try
	{
		rrf2 = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
		std::cout << *rrf2 << std::endl; 
		Bureaucrat b2("DUDE2", 2);
		b2.signForm(*rrf2);
		b2.executeForm(*rrf2);
		//delete rrf2;
	}
	catch(const std::exception& e)
	{
		//delete rrf2;
		std::cerr << ORANGE << e.what() << END << '\n';
	}
	try
	{
		rrf3 = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		std::cout << *rrf3 << std::endl; 
		//delete rrf3;
	}
	catch(const std::exception& e)
	{
		//delete rrf3;
		std::cerr << ORANGE << e.what() << END << '\n';
	} 
	try
	{
		rrf4 = someRandomIntern.makeForm("andsdndanadn", "Bender");
		std::cout << *rrf4 << std::endl; 
		//delete rrf4;
	}
	catch(const std::exception& e)
	{
		//delete rrf4;
		std::cerr << ORANGE << e.what() << END << '\n';
	}
	delete rrf1;
	delete rrf2;
	delete rrf3;
	delete rrf4;
	return 0;
}


/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed */