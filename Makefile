CC		=	g++

NAME	=	a.out

SRC 	=	main.cpp								\
			src/classes/Literal.cpp					\
			src/operations/literal_operations.cpp

OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
