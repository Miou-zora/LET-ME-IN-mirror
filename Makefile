##
## EPITECH PROJECT, 2021
## B-PSU-100-NAN-1-1-myprintf-alexandre.franquet [WSL: Ubuntu]
## File description:
## Makefile
##

SRC 		= 	src/data_to_array_str.c	\
				src/get_len_array.c		\

MAIN		=	src/main.c

TEST_FONC	=	#	tests/test_put_users_rights.c

MAIN_DEBUG	=	# src/test_main.c	\

OBJ_SRC		=	$(SRC:.c=.o)
OBJ_MAIN	=	$(MAIN:.c=.o)

OBJ_TEST	+=	$(OBJ_SRC)
OBJ_TEST	+=	$(TEST_FONC:.c=.o)

CC			=	gcc

TEST_BINARY	=	unit_tests

CFLAGS		=	-Wall -Wextra -Wshadow -I./include

TESTS_FLAGS	=	--coverage -lcriterion -I./include

LFLAGS	=	-L./lib -lmy

NAME		=	temp_name

NAME_DEBUG	=	#	debug

RM			=	rm -rf

MK			=	make -s

MV			=	mv

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	make_lib $(OBJ_SRC)
			$(CC) $(OBJ_SRC) $(MAIN) $(CFLAGS) -o $(NAME) $(LFLAGS)
			@printf "\033[33m[Message]\033[39m %s\n" $(NAME)

make_lib:
			@$(MK) -C lib/my/

debug:		CFLAGS += -g
debug:		re

clean:
			@$(RM) $(OBJ_MAIN)
			@$(RM) $(OBJ_SRC)
			@$(RM) $(OBJ_TEST)
			@$(MK) -C lib/my/ clean

tests_run:		tclean $(NAME)
		$(CC) $(SRC) $(TEST_FONC) $(TESTS_FLAGS) $(LFLAGS) -o $(TEST_BINARY)
			./$(TEST_BINARY)
			@$(MV) *.gc* tests
			gcovr -e tests
			gcovr -e tests -bu
			@$(MK) tclean

tclean:
			@$(RM) tests/*.gc*
			@$(RM) *.gc*
			@$(RM) $(TEST_BINARY)

fclean:			clean
			@$(RM) *.gc*
			@$(RM) $(NAME)
			@$(RM) $(TEST_BINARY)
			@$(RM) $(NAME_DEBUG)
			@$(RM) ./lib/libmy.a
			@$(MK) -C lib/my/ fclean
			@printf "\033[33m[Message]\033[39m FClean reussi\n"

re:				fclean all

.PHONY:		fclean clean re all tests_run cpy
