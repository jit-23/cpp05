#include "Bureaucrat.hpp"

int main()
{
    {	
		std::cout << std::endl;
		std::cout << GREEN << "First test - simple initialization of diferent constructors" << END << std::endl << std::endl;
		
		Bureaucrat b1; // void constructor
		Bureaucrat b2("Fernando"); // only name 
		Bureaucrat b3("Lucart", 3); // name + grade
	
		std::cout << BLUE << "Operator overload to print those bureaucrats!!" <<  END << std::endl;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		
		std::cout << BLUE << "Increment and Decrement of bureaucrats!!" <<  END << std::endl;
		
		//std::cout << b1 << std::endl;

		std::cout << "\n" << BLUE << b1.getName() << END << std::endl;
		for (short i = 0; i < 3; i++)
		{
			std::cout << b1 << std::endl;
			b1.incremment_grade();
		}
		for (short i = 0; i < 5; i++)
		{
			std::cout << b1 << std::endl;
			b1.decremment_grade();
		}
		std::cout << "\n" << BLUE << b3.getName() << END << std::endl;
		for (short i = 0; i < 5; i++)
		{
			std::cout << b3 << std::endl;
			b3.incremment_grade();
		}
	}
	{
		std::cout << RED << "*****************\n" << END << std::endl;  
		std::cout << GREEN << "Second test - initialization of non valid grades" << END << std::endl << std::endl;
		Bureaucrat b1("Fde-jesu", 200); // non valid, to low
		Bureaucrat b2("bureaucrat_4", 0); // non valid, to high


		std::cout << b1 << std::endl << std::endl;
		std::cout << b2 << std::endl;
	}

	//Bureaucrat b1();
    //std::cout << b1.getGrade() << std::endl;
    //Bureaucrat b2(710);
    //std::cout << b2.getGrade() << std::endl;
    //Bureaucrat b3("b3");
    //std::cout << b3.getGrade() << std::endl;
    //Bureaucrat b4("b4", 130);
    //std::cout << b4.getGrade() << std::endl;
//
	//std::cout << "-----------------------" << std::endl;
	//
	//std::cout << b4 << std::endl;
//
    return 0;
}
