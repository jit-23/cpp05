#ifndef BUREAUCRAT 
#define BUREAUCRAT

#include <iostream>
#include <cstring>
#include <cctype>


class Bureaucrat
{
private:
     std::string name;
    int grade;
public:
    int getGrade()const;
    std::string getName()const;
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat&  operator=(const Bureaucrat &other);
    Bureaucrat();
    ~Bureaucrat();
};


#endif