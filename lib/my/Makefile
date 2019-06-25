##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Make lib
##

SRC		=	my_putchar.c \
			my_putstr.c \
			my_strcmp.c \
			my_strcpy.c \
			my_strlen.c \
			my_strncmp.c \
			my_strncpy.c \
			my_split.c \
			my_realloc.c \
			my_getnbr.c \
			my_put_nbr.c \
			get_next_line.c \
			my_str_to_int.c \
			my_listlen.c \
			my_strcat.c \
			my_strdup.c

DEST_LIB_DIR	=	.

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -g

NAME	=	libmy.a

all: $(NAME) $(GCC)

$(GCC):
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
