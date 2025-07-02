#include "Bureaucrat.hpp"
#include "Form.hpp"

void explain_color_scheme(){

	std::cout << GREEN << "GREEN" << END << ":Constructors;"<< std::endl;
	std::cout << BLUE << "BLUE" << END << ":operator Overload;"<< std::endl;
	std::cout << RED << "RED" << END << ":Destructor;"<< std::endl;
	std::cout << ORANGE << "ORANGE" << END << ":ERR_MSG of try/catch;"<< std::endl;
}

int main()
{

	std::cout << OLIVE <<  "# COLOR  SCHEME #"<<  END<<std::endl;
	explain_color_scheme();
	std::cout << std::endl;

	std::cout << DARK_GRAY<<"\n#================================================#" << END <<  std::endl;
	std::cout << DARK_GRAY << "# First test(1) - Creation of Form 'f(n)';       #" << END <<  std::endl;
	std::cout << DARK_GRAY << "# Application of try/catch if grade out of bound #" << END <<  std::endl;
	std::cout << DARK_GRAY << "#================================================#" << END <<  std::endl <<  std::endl;

	try
	{
		Form f1;
		Form f2("my_form", 50, 30);
		std::cout << BLUE << "Operator overload (f1):\n" <<  f1<< END << std::endl;
		std::cout << BLUE << "Operator overload (f2):\n" <<  f2<< END << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr<< ORANGE << e.what()<<END << '\n';
	}
	std::cout << DARK_GRAY<<"\n#================================================#" << END <<  std::endl;
	std::cout << DARK_GRAY << "# First test(1.1) - creation of Forms(f3,f4);    #" << END <<  std::endl;
	std::cout << DARK_GRAY << "# Out of boud grades(to Low)                     #" << END <<  std::endl;
	std::cout << DARK_GRAY << "#================================================#" << END <<  std::endl <<  std::endl;
	try
	{
		Form f3("tratado da 42",200/* 140 */, 130);
		std::cout << BLUE << "Operator overload (f3):\n"<< END <<  f3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr<< ORANGE << e.what()<<END << '\n';
	}
	try
	{
		Form f4("random form", 20, 200/* 140 */);
		std::cout << BLUE << "Operator overload (f4):\n"<< END <<  f4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr<< ORANGE << e.what()<<END << '\n';
	}

	std::cout << DARK_GRAY<<"\n#================================================#" << END <<  std::endl;
	std::cout << DARK_GRAY << "# First test(1.2) - creation of Forms(f5,f6);    #" << END <<  std::endl;
	std::cout << DARK_GRAY << "# Out of boud grades(to High)                    #" << END <<  std::endl;
	std::cout << DARK_GRAY << "#================================================#" << END <<  std::endl <<  std::endl;
	try
	{
		Form f5("tratado da 21",0/* 1 */, 130);
		std::cout << BLUE << "Operator overload (f5):\n"<< END <<  f5 << std::endl; // its does not execute bcs of catch(try to put a valid value)
	}
	catch(const std::exception& e)
	{
		std::cerr<< ORANGE << e.what()<<END << '\n';
	}
	try
	{
		Form f6("not_random form", 20, 0/* 1 */);
		std::cout << BLUE << "Operator overload (f6):\n"<< END <<  f6 << std::endl; // its does not execute bcs of catch (try to put a valid value)
	}
	catch(const std::exception& e)
	{
		std::cerr<< ORANGE << e.what()<<END << '\n';
	}

	std::cout << DARK_GRAY<<"\n#=====================================================#" << END <<  std::endl;
	std::cout << DARK_GRAY << "# First test(2) - Application of Bureaucrat x Form    #" << END <<  std::endl;
	std::cout << DARK_GRAY << "# Application of BeSigned() and SignForm              #" << END <<  std::endl;
	std::cout << DARK_GRAY << "#=====================================================#" << END <<  std::endl <<  std::endl;


	std::cout << DARK_GRAY<<"\n#=====================================================#" << END <<  std::endl;
	std::cout << DARK_GRAY << "# First case(2.1): bureacrat " << GREEN << "CAN"<<DARK_GRAY<< " Sign Form            #" << END <<  std::endl;
	std::cout << DARK_GRAY << "#=====================================================#" << END <<  std::endl <<  std::endl;	
	try
	{
		
		Bureaucrat b1("The president", 25);
		Form f1("Test_form", 30,20);
		std::cout << CYAN << "#============#Bureaucrat info#===========#"<< END << std::endl;
		std::cout << BLUE << b1 << END <<  std::endl;
		std::cout << CYAN << "#===============#Form info#==============#"<< END << std::endl;
		std::cout << BLUE << f1 << END <<  std::endl;
		std::cout << CYAN << "#========================================#"<< END << std::endl;
		std::cout << CYAN << "#===#Bureaucrat try to sign form Form#===#"<< END << std::endl<< std::endl;
		std::cout << CYAN << "Line of code: b1.signForm(f1);" <<END<< std::endl<< std::endl;
		b1.signForm(f1);
		std::cout << CYAN << "#===============#Form info#==============#"<< END << std::endl;
		std::cout << BLUE << f1 << END <<  std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr<< ORANGE << e.what()<<END << '\n';
	}
	
	std::cout << DARK_GRAY<<"\n#=====================================================#" << END <<  std::endl;
	std::cout << DARK_GRAY << "# First case(2.2): bureacrat " << RED << "CANNOT"<<DARK_GRAY<< " Sign Form         #" << END <<  std::endl;
	std::cout << DARK_GRAY << "#=====================================================#" << END <<  std::endl <<  std::endl;

	try
	{
		
		Bureaucrat b1("ramdon_dude", 120);
		Form f1("Test_form", 30,20);
		std::cout << CYAN << "#============#ramdon_dude info#===========#"<< END << std::endl;
		std::cout << BLUE << b1 << END <<  std::endl;
		std::cout << CYAN << "#================#Form info#==============#"<< END << std::endl;
		std::cout << BLUE << f1 << END <<  std::endl;
		std::cout << CYAN << "#=========================================#"<< END << std::endl;
		std::cout << CYAN << "#===#Bureaucrat try to sign form Form#====#"<< END << std::endl<< std::endl;
		std::cout << CYAN << "Line of code: b1.signForm(f1);" <<END<< std::endl<< std::endl;
		b1.signForm(f1);
		std::cout << CYAN << "#================#Form info#==============#"<< END << std::endl;
		std::cout << BLUE << f1 << END <<  std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr<< ORANGE << e.what()<< END << '\n';
	}


}
