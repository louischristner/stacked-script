CC		=	g++

NAME	=	a.out

SRC 	=	main.cpp								\
			src/classes/Engine.cpp					\
			src/classes/Literal.cpp					\
			src/operations/literal_operations.cpp	\
			src/operations/stack_operations.cpp

OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

tests:
	make -C test
	make run -C test

clean:
	rm -f $(OBJ)
	make clean -C test

fclean:	clean
	rm -f $(NAME)
	make fclean -C test

re:	fclean all
	make re -C test

.PHONY: all clean fclean re
