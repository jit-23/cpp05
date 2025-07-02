NAME:=execute
CXXFLAGS:= -Wall -Werror -Wextra -std=c++98
CXX:= c++
SRC:= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
OBJ:=$(patsubst %.cpp, %.o, $(SRC))

all: ${NAME}

${NAME}: ${OBJ}
	${CXX}  ${CXXFLAGS} ${OBJ} -o ${NAME}
clean:
	rm -f ${OBJ}
	rm -f *_shrubbery
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all re  fclean clean
