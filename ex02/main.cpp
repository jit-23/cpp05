#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

void explain_color_scheme(){

	std::cout << GREEN << "GREEN" << END << ":Constructors;"<< std::endl;
	std::cout << BLUE << "BLUE" << END << ":operator Overload;"<< std::endl;
	std::cout << RED << "RED" << END << ":Destructor;"<< std::endl;
	std::cout << ORANGE << "ORANGE" << END << ":ERR_MSG of try/catch;"<< std::endl;
}

int main()
{

	Bureaucrat b1("asd", 2);
	ShrubberyCreationForm S("ASD");
	std::cout << S << std::endl; 
	std::cout << S.GetTarget() << std::endl; 
	S.execute(b1);
	/* code */
	return 0;
}
