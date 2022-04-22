##
## EPITECH PROJECT, 2021
## B-PSU-100-NAN-1-1-myprintf-alexandre.franquet [WSL: Ubuntu]
## File description:
## Makefile
##

SRC 		= 	src/lem_in.c 									\
				src/load_data/load_data_from_file.c 			\
				src/useful_fonctions/is_number.c 				\
				src/useful_fonctions/remove_comments.c 			\
				src/load_data/check_error_file.c 				\
				src/load_data/get_value.c 						\
				src/load_data/save_data_and_rooms.c				\
				src/useful_fonctions/free_array.c 				\
				src/load_data/error_in_data.c 					\
				src/useful_fonctions/my_putstr_error.c 			\
				src/load_data/check_name_path.c 				\
				src/useful_fonctions/remove_space.c 			\
				src/display/display_info.c 						\
				src/display/display_path.c 						\
				src/path_finding/remove_path.c 					\
				src/path_finding/get_shortest_path.c 			\
				src/display/append_int_list.c 					\
				src/display/count_int_array.c 					\
				src/display/display_movement.c 					\
				src/display/get_ants.c 							\
				src/display/get_len_paths.c 					\
				src/display/get_pos_paths.c 					\

LISTSRC		=	src/linked_list/build_linked_list.c 	\
				src/linked_list/display_linked_list.c 	\
				src/linked_list/free_linked_list.c 		\
				src/linked_list/build_tab_node.c		\
				src/linked_list/link_nodes.c

MAIN		=	src/main.c

TEST_FONC	=	tests/test_is_number.c 				\
				tests/test_remove_comments.c 		\
				tests/test_check_error_file.c       \
				tests/test_comter_error_init.c		\
				tests/test_get_value_start.c		\
				tests/test_get_value_end.c			\
				tests/test_analyse_get_value.c		\
				tests/test_free_array.c				\
				tests/test_path_finding.c

OBJ_SRC		=	$(SRC:.c=.o)
OBJ_LIST	= 	$(LISTSRC:.c=.o)
OBJ_MAIN	=	$(MAIN:.c=.o)

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
		$(CC) $(SRC) $(LISTSRC) $(TEST_FONC) $(TESTS_FLAGS) $(LFLAGS) -o	\
		$(TEST_BINARY)
			./$(TEST_BINARY)
			gcovr -e tests
			gcovr -e tests -bu

tclean:
			@$(RM) tests/*.gc*
			@$(RM) *.gc*
			@$(RM) $(TEST_BINARY)

fclean:			clean tclean
			@$(RM) $(NAME)
			@$(RM) $(NAME_DEBUG)
			@$(RM) ./lib/libmy.a
			@$(MK) -C lib/my/ fclean
			@printf "\033[33m[Message]\033[39m FClean reussi\n"

re:				fclean all

.PHONY:		fclean clean re all tests_run cpy
