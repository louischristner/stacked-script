CC		=	g++

NAME	=	a.out

SRC 	=	main.cpp								    \
			src/classes/Engine.cpp					    \
			src/classes/Literal.cpp					    \
			src/operations/literal_operations.cpp	    \
			src/operations/stack_operations.cpp		    \
			src/operations/condition_operations.cpp	    \
			src/operations/loop_operations.cpp		    \
			src/parser/parser.cpp					    \
			src/parser/literal_parser.cpp			    \
            src/parser/function_parser.cpp              \
			src/parser/operation_parser.cpp			    \
            src/parser/user_defined_function_parser.cpp \
			src/reader/reader.cpp

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
