##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

SRC =   src/main.c	\
		src/mysh.c	\
		src/interpretor.c	\
		src/environnment.c	\
		src/commands/my_cd.c	\
		src/commands/cd_errors.c	\
		src/commands/errors_msg.c	\
		src/commands/my_exit.c	\
		src/commands/my_env.c	\
		src/commands/my_setenv.c	\
		src/commands/my_unsetenv.c

OBJ =   $(SRC:.c=.o)

NAME    =   mysh

CFLAGS  +=  -I include -Wall -Wextra
LDFLAGS +=  -L lib/my -lmy

TEST = @gcc -o unit_tests src/interpretor.c src/environnment.c src/commands/my_cd.c src/commands/cd_errors.c src/commands/errors_msg.c src/commands/my_exit.c src/commands/my_env.c src/commands/my_setenv.c src/commands/my_unsetenv.c tests/tests_mysh_env.c tests/tests_mysh_setenv.c tests/tests_mysh_unsetenv.c tests/tests_mysh_exit.c tests/tests_mysh_cd.c tests/tests_mysh.c $(LDFLAGS) $(CFLAGS) --coverage -lcriterion

all:    $(NAME)

$(NAME):    $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
	make -C lib/my
	$(TEST)
	gcc -o tests/my_segfault tests/test_main_segfault.c
	./unit_tests

clean:
	@make clean -C lib/my/ --no-print-directory
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/my/ --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean