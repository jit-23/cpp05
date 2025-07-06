#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

void explain_color_scheme(){

	std::cout << GREEN << "\nGREEN" << END << ":Constructors;"<< std::endl;
	std::cout << BLUE << "BLUE" << END << ":operator Overload;"<< std::endl;
	std::cout << RED << "RED" << END << ":Destructor;"<< std::endl;
	std::cout << ORANGE << "ORANGE" << END << ":ERR_MSG of try/catch;"<< std::endl;
}

int main()
{		
	explain_color_scheme();
	
	std::cout << OLIVE << "#=================================================#" << END <<  std::endl;
	std::cout << OLIVE << "# First test(1) - Creation of Bureaucrats b(n's)  #" << END <<  std::endl;
	std::cout << OLIVE << "# and execution of all Forms                      #" << END <<  std::endl;
	std::cout << OLIVE << "#=================================================#" << END <<  std::endl <<  std::endl;

	std::cout << OLIVE << "\n# == (1.0) ShrubberyCreationForm(try to execute with no signature) == #" << END << std::endl;
	
	try
	{
		/* try to execute a NOT SIGNING form */
		Bureaucrat b0("guy0", 130);
		ShrubberyCreationForm S("FORM0!");
		std::cout << S << std::endl;
		b0.executeForm(S);
	}
	catch(const std::exception& e)
	{
		std::cerr <<ORANGE<< e.what() <<END<< '\n';
	}
	

	/*  */
	std::cout << OLIVE << "\n# == (1.1) ShrubberyCreationForm == #" << END << std::endl;
	try
	{
		Bureaucrat b1("this guy", 2);
		ShrubberyCreationForm S("FORM1!");
		b1.signForm(S);
		std::cout << S << std::endl;
		b1.executeForm(S); 
		std::cout << S << std::endl; 

	}
	catch(const std::exception& e)
	{
		std::cerr <<ORANGE << e.what() <<END<< '\n';
	}
	std::cout << OLIVE << "\n# == (1.2)  RobotomyRequestForm == #" << END << std::endl;
	try
	{
		Bureaucrat b2("that guy", 2);
		RobotomyRequestForm S("FORM2!");
		b2.signForm(S);
		std::cout << S << std::endl; 
		b2.executeForm(S);
	}
	catch(const std::exception& e)
	{
		std::cerr <<ORANGE << e.what() <<END<< '\n';
	}
	std::cout << OLIVE << "\n# == (1.3) PresidentialPardonForm == #" << std::endl;
	try
	{
		Bureaucrat b3("Fernando", 2);
		PresidentialPardonForm S("FORM3!");
		b3.signForm(S);
		std::cout << S << std::endl; 
		b3.executeForm(S);
	}
	catch(const std::exception& e)
	{
		std::cerr <<ORANGE << e.what() <<END<< '\n';
	}
	std::cout << OLIVE << "\n# == (1.4) NON VALID GRADE FOR SIGNING == #" << std::endl;
	try
	{
		Bureaucrat b4("LUCAS", 150);
		PresidentialPardonForm S("FORM4!");
		b4.signForm(S);
		std::cout << S << std::endl; 
		b4.executeForm(S);
	}
	catch(const std::exception& e)
	{
		std::cerr <<ORANGE << e.what() <<END<< '\n';

	}
	
	return 0;
}

/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed */