##
## EPITECH PROJECT, 2021
## B-PSU-100-NAN-1-1-myprintf-alexandre.franquet [WSL: Ubuntu]
## File description:
## Makefile
##

SRC 		= 	src/lem_in.c 							\
				src/load_data_from_file.c 				\
				src/is_number.c 						\
				src/remove_comments.c 					\
				src/check_error_file.c 					\
				src/get_value.c 						\
				src/save_data_and_rooms.c				\
				src/free_array.c 						\
				src/error_in_data.c 					\
				src/my_putstr_error.c 					\

LISTSRC		=	src/linked_list/build_linked_list.c 	\
				src/linked_list/display_linked_list.c 	\
				src/linked_list/free_linked_list.c 		\

MAIN		=	src/main.c

TEST_FONC	=	tests/test_is_number.c 				\
				tests/test_remove_comments.c 		\
				tests/test_check_error_file.c       \
				tests/test_comter_error_init.c		\
				tests/test_get_value_start.c		\
				tests/test_get_value_end.c			\
				tests/test_analyse_get_value.c		\

OBJ_SRC		=	$(SRC:.c=.o)
OBJ_LIST	= 	$(LISTSRC:.c=.o)
OBJ_MAIN	=	$(MAIN:.c=.o)

OBJ_TEST	+=	$(OBJ_SRC)
OBJ_TEST	+=	$(OBJ_LIST)
OBJ_TEST	+=	$(TEST_FONC:.c=.o)

CC			=	gcc

TEST_BINARY	=	unit_tests

CFLAGS		=	-Wall -Wextra -Wshadow -Werror -I./include

TESTS_FLAGS	=	--coverage -lcriterion -I./include

LFLAGS		=	-L./lib -lmy

NAME		=	lem_in

RM			=	rm -rf

MK			=	make -s

MV			=	mv

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	make_lib $(OBJ_SRC) $(OBJ_LIST) $(OBJ_MAIN)
			$(CC) $(OBJ_SRC) $(OBJ_LIST) $(OBJ_MAIN) $(CFLAGS) -o $(NAME) \
			$(LFLAGS)
			@printf "\033[33m[Message]\033[39m %s\n" $(NAME)

make_lib:
			@$(MK) -C lib/my/

debug:		CFLAGS += -g
debug:		re

clean:
			@$(RM) $(OBJ_MAIN)
			@$(RM) $(OBJ_SRC)
			@$(RM) $(OBJ_LIST)
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
