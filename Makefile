##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

SRC =   src/main.c					\
		src/mysh.c					\
		src/interpretor.c			\
		src/semicolons.c			\
		src/commands/command.c		\
		src/environnment.c			\
		src/commands/my_cd.c		\
		src/commands/cd_errors.c	\
		src/commands/errors_msg.c	\
		src/commands/my_exit.c		\
		src/commands/my_env.c		\
		src/commands/my_setenv.c	\
		src/commands/my_unsetenv.c

OBJ =   $(SRC:.c=.o)

NAME    =   mysh

CFLAGS  +=  -I include -Wall -Wextra
LDFLAGS +=  -L lib/my -lmy

TEST = @gcc -o unit_tests src/interpretor.c src/environnment.c src/commands/my_cd.c src/commands/cd_errors.c src/commands/errors_msg.c src/commands/my_exit.c src/commands/my_env.c src/commands/my_setenv.c src/commands/my_unsetenv.c tests/tests_mysh_env.c tests/tests_mysh_setenv.c tests/tests_mysh_unsetenv.c tests/tests_mysh_exit.c tests/tests_mysh_cd.c tests/tests_mysh.c $(LDFLAGS) $(CFLAGS) --coverage -lcriterion

all:    $(NAME)

$(NAME):    $(OBJ)
		@$(ECHO)
		@for MAKE_PATH in $(LIB_PATHS) ; do \
			make -C $$MAKE_PATH -s ; \
		done
		@gcc -o $(NAME) $(OBJ) $(LDFLAGS) \
		&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT)

clean:
		@for MAKE_PATH in $(LIB_PATHS) ; do \
			make clean -C $$MAKE_PATH -s ; \
		done
		@rm -f $(OBJ)
		@mr_clean
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN "$(DEFAULT))

fclean: clean
		@for MAKE_PATH in $(LIB_PATHS) ; do \
			make fclean -C $$MAKE_PATH -s ; \
		done
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@mr_clean
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN "$(DEFAULT))

re: fclean all

tests_run:
	make -C lib/my
	$(TEST)
	gcc -o tests/my_segfault tests/test_main_segfault.c
	./unit_tests

debug: CFLAGS += -g
debug: re
	valgrind ./$(NAME)

free: CFLAGS += -g
free: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

%.o :		%.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev

.PHONY: all clean fclean


ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"
#SHELL  =       "\e[0;0m"

DEFAULT =       "\e[0m"
BOLD    =       "\e[1m"
DIM     =       "\e[2m"
UNDLN   =       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;37m"

BLACK   =       "\e[30m"
RED     =       "\e[31m"
GREEN   =       "\e[32m"
YELLOW  =       "\e[33m"
BLUE    =       "\e[34m"
MAGEN   =       "\e[35m"
CYAN    =       "\e[36m"
WHITE   =       "\e[1;37m"

LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLOW    =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGEN     =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"