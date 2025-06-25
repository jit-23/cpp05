#include "Bureaucrat.hpp"
#include "Form.hpp"



int main()
{
	Bureaucrat	b1;
	Form		paper1("Tratado da 42", 100, 80);
	Form		paper2(paper1);
	

	std::cout << paper2 << std::endl;

    return 0;
}
