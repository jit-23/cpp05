#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1;
    Bureaucrat b2(710);
    Bureaucrat b3("b3");
    Bureaucrat b4("b4", 130);

    std::cout << b1.getGrade() << std::endl;


    return 0;
}
