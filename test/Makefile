CC		=	g++

NAME	=	tests

SRC		=	test.cpp									\
			../src/classes/Engine.cpp					\
			../src/classes/Literal.cpp					\
			../src/operations/literal_operations.cpp	\
			../src/operations/stack_operations.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

run:
	./$(NAME)

.PHONY:	all
