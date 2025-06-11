#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1;
    std::cout << b1.getGrade() << std::endl;
    Bureaucrat b2(710);
    std::cout << b2.getGrade() << std::endl;
    Bureaucrat b3("b3");
    std::cout << b3.getGrade() << std::endl;
    Bureaucrat b4("b4", 130);
    std::cout << b4.getGrade() << std::endl;

	std::cout << "-----------------------" << std::endl;
	
	std::cout << b4 << std::endl;

    return 0;
}
