#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* CONSTRUCTORS */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "the president", 137, 145)// , grade_to_execute(137), grade_to_sign(145)
{
    std::cout << "ShrubberyCreationForm Default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", _target, 137, 145)
{
    std::cout << "ShrubberyCreationForm Default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :  AForm(other)
{
    std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other ) {
    if (this != &other)
		this->SetFormSignature(other.GetFormSignature_bool());
    return (*this);
}

/* 

bool ShrubberyCreationForm::BeSigned(const  Bureaucrat &other) {
	if (this->GetFormSignature_bool())
		return (false);
	else
	{
		if (other.getGrade() <= this->GetGradeToSign())
		{
			this->SetFormSignature(true);
			return (true);
		}
		try
		{
			std::string err_msg;
			err_msg = this->GetFormName() + std::string(" was not signed!") ;
			throw(GradeTooLowException(err_msg));
		}
		catch(const std::exception& e) { std::cerr << e.what() << '\n';}
		return (false);
	}
} */

void ShrubberyCreationForm::execute_it() const
{
	std::string shrubbery = get_tree();
	std::cout << this->GetTarget() << std::endl;
	std::string file_name = this->GetTarget() + std::string("_shrubbery");
	std::fstream outfile;
	outfile.open(file_name.c_str(), std::ios::out);
	if (outfile)
	{
		outfile << shrubbery;
		outfile.close();
		std::cout << file_name << " Created!!" << std::endl;
	}
	else
		std::cout << "Error: "<< file_name << " was not Created!!" << std::endl;
}


/* SETTERS */


/* DESTRUCTOR */
ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << RED << "ShrubberyCreationForm Default Destructor called!" << END << std::endl;
}





/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */
/* ------------------------------ */


std::string get_tree()
{
	return ("      v .   ._, |_  .,\n"
	"   `-._\\/  .  \\ /    |/_\n"
	"       \\\\  _\\, y | \\//\n"
	" _\\_.___\\\\, \\\\/ -.\\||\n"
	"  `7-,--.`._||  / / ,\n"
	"  /'     `-. `./ / |/_.'\n"
	"           |    |//\n"
	"           |_    /\n"
	"           |-   |\n"
	"           |   =|\n"
	"           |    |\n"
	"----------------------------\n");
}