CC		=	g++

NAME	=	tests

SRC		=	literal_tests.cpp							    \
			stack_tests.cpp								    \
			parser_tests.cpp							    \
			reader_tests.cpp							    \
			../src/classes/Engine.cpp					    \
			../src/classes/Literal.cpp					    \
			../src/operations/literal_operations.cpp	    \
			../src/operations/stack_operations.cpp		    \
			../src/operations/condition_operations.cpp	    \
			../src/operations/loop_operations.cpp		    \
			../src/parser/parser.cpp					    \
			../src/parser/literal_parser.cpp			    \
			../src/parser/function_parser.cpp			    \
			../src/parser/operation_parser.cpp			    \
            ../src/parser/user_defined_function_parser.cpp  \
			../src/reader/reader.cpp

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
