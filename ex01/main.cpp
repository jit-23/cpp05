#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << GREEN << "First test - simple initialization of diferent constructors" << END << std::endl << std::endl;
	
	Bureaucrat b3("Lucart", 20); // name + grade
	
	Form paper1("tratado da 42", 20, 10); // 20 to sign , 10 to execute
	std::cout << paper1 << std::endl;
    return 0;
}



/* Now that you have bureaucrats, let’s give them something to do. What better activity
could there be than filling out a stack of forms?
Let’s create a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it is not).
• A constant grade required to sign it.
• A constant grade required to execute it.
All these attributes are private, not protected.
//.**********DONE TILL HERE****************** 
The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
As before, write getters for all attributes and overload the insertion («) operator to
print all the form’s information.
8
C++ - Module 05 Repetition and Exceptions
Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
(greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.
Then, modify the signForm() member function in the Bureaucrat class. This func-
tion must call Form::beSigned() to attempt to sign the form. If the form is signed
successfully, it will print something like:
<bureaucrat> signed <form>
Otherwise, it will print something like:
<bureaucrat> couldn’t sign <form> because <reason>.
Implement and submit some tests to ensure everything works as expected.
9
 */