CC		=	g++

NAME	=	tests

SRC		=	literal_operations.cpp						\
			../src/classes/Engine.cpp					\
			../src/classes/Literal.cpp					\
			../src/operations/literal_operations.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

run:
	./$(NAME)

.PHONY:	all
