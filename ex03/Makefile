NAME:=intern
CXXFLAGS:= -Wall -Werror -Wextra -std=c++98
CXX:= c++
SRC:= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJ:=$(patsubst %.cpp, %.o, $(SRC))

all: ${NAME}

${NAME}: ${OBJ}
	${CXX}  ${CXXFLAGS} ${OBJ} -o ${NAME}
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all re  fclean clean
