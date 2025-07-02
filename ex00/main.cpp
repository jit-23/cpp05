#include "Bureaucrat.hpp"

int main()
{
	std::cout << OLIVE << "#===================================================================================#" << END <<  std::endl;
	std::cout << OLIVE << "# First test(1) - Creation of Bureaucrat b1 and b2 decrement/increment till failure #" << END <<  std::endl;
	std::cout << OLIVE << "#===================================================================================#" << END <<  std::endl <<  std::endl;
	/* First Test */
	try
	{
		Bureaucrat b1(2);
		std::cout << PURPLE <<"Operator overload(b1): "<<END <<  b1 << std::endl;
		std::cout << BLUE << b1.getName() << " incremment till failure:" << END << std::endl;
		for (short i = 0; i < 3; i++)
		{
			std::cout << "Grade : " <<  b1.getGrade() << std::endl;
			b1.incremment_grade();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << END<< '\n';
	}
	/*******************************/
	try
	{
		Bureaucrat b2("Fernando", 147); //valid Bureaucrat 
		std::cout <<PURPLE<< "Operator overload(b2): "<< END <<  b2 << std::endl;
		std::cout << BLUE << b2.getName() << " decremment till failure:" << END << std::endl;
		for (short i = 0; i < 5; i++)
		{
			std::cout << "Grade : "<< b2.getGrade() << std::endl;
			b2.decremment_grade();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << END<< '\n';
	}
	std::cout << OLIVE << "\n#=====================================================#" << END <<  std::endl;
	std::cout << OLIVE << "# Second test(2) - Creation of Bureaucrat b3, b4, b5; #" << END <<  std::endl;
	std::cout << OLIVE << "# Application of Copy constructor and  operator=      #" << END <<  std::endl;
	std::cout << OLIVE << "#=====================================================#" << END <<  std::endl <<  std::endl;
	/* Second test  */
	try
	{
		Bureaucrat b3("Lucart", 70);
		Bureaucrat b4(b3);
		Bureaucrat b5("fifth Bureaucrat", 140);

		std::cout << PURPLE << "Operator overload (b3): " <<END<<  b3 << std::endl;
		std::cout << PURPLE <<"Operator overload (b4) : " <<END<<  b4 << std::endl;
		std::cout << PURPLE <<"Operator overload (b5) : " <<END<<  b5 << std::endl;
		
		b4 = b5;
		std::cout << "b4 = b5;" << std::endl;
		std::cout << PURPLE <<"Operator overload(b4)  : " <<END<<  b4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << ORANGE << e.what() << END<< '\n';
	}
    return 0;
}
