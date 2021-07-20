CC		=	g++

NAME	=	tests

SRC		=	literal_tests.cpp							\
			stack_tests.cpp								\
			../src/classes/Engine.cpp					\
			../src/classes/Literal.cpp					\
			../src/operations/literal_operations.cpp	\
			../src/operations/stack_operations.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -lcriterion -o $(NAME)

run:
	./$(NAME)

.PHONY:	all
