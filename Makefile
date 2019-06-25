##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

LIB_PATH	=	./lib/my

SRC_proj	=	src/main.c \
			src/commands/commands.c \
			src/commands/cd.c \
			src/commands/setenv.c \
			src/parsing.c \
			src/redirection/semicolon.c \
			src/redirection/pipe.c \
			src/redirection/out.c \
			src/redirection/in.c \
			src/environnement.c \
			src/utils.c \
			src/free.c \
			src/error.c \
			src/count.c

SRC_test	= 	tests/test.c

OBJ		=	$(SRC_main:.c=.o) $(SRC_proj:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -g

LDFLAG		=	-lcriterion -lgcov

NAME	=	mysh

MAKE	=	@make -s -C

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) $(LIB_PATH) re
	@gcc $(OBJ) -o $(NAME) $(CFLAGS) -I./include -L./lib/my -lmy

tests_run:
	cc -o units $(SRC_proj) $(SRC_test) $(LDFLAG) --coverage
	./units

clean:
	rm -f $(OBJ) *.gcno *.gcna *.gch

fclean: clean_lib clean
	rm -f $(NAME)

re: fclean all

clean_lib:
	$(MAKE) $(LIB_PATH) fclean
