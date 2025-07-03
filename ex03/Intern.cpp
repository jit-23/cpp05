#include  "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Defaut Construct called!!" << std::endl;
} 

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy Construct called!!" << std::endl;
    /* nothing to copy!!!! */
} 

Intern& Intern::operator=(const Intern &other)
{  
    return (*this);
} 

Intern::~Intern()
{
    std::cout << "Intern Defaut destructor called!!" << std::endl;
}


AForm& Intern::makeForm(const std::string form_name, const std::string _target)
{

}

/* Chapter VI
Exercise 03: At least this beats
coffee-making
Exercise : 03
At least this beats coffee-making
Turn-in directory : ex03/
Files to turn in : Files from previous exercises + Intern.{h, hpp}, Intern.cpp
Forbidden functions : None
Since filling out forms all day would be too cruel for our bureaucrats, interns exist to
take on this tedious task. In this exercise, you must implement the Intern class. The
intern has no name, no grade, and no unique characteristics. The only thing bureaucrats
care about is that they do their job.
However, the intern has one key ability: the makeForm() function. This function
takes two strings as parameters: the first one represents the name of a form, and the
second one represents the target of the form. It returns a pointer to a AForm object
(corresponding to the form name passed as a parameter), with its target initialized to
the second parameter.
It should print something like:
Intern creates <form>
If the provided form name does not exist, print an explicit error message.
12
C++ - Module 05 Repetition and Exceptions
You must avoid unreadable and messy solutions, such as using an excessive if/el-
seif/else structure. This kind of approach will not be accepted during the evaluation
process. You’re not in the Piscine (pool) anymore. As usual, you must test everything
to ensure it works as expected.
For example, the following code creates a RobotomyRequestForm targeted at
"Bender":
{
Intern someRandomIntern;
AForm* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
13
 */