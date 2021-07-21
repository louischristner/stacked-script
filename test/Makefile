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

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re:	fclean all

.PHONY:	all clean fclean re
