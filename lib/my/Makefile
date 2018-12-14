##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c		\
		my_strcmp.c		\
		my_strlen.c		\
		my_getnbr.c		\
		my_putstr.c		\
		my_put_nbr.c		\
		my_strdup.c		\
		my_strcpy.c		\
		mal.c		\
		mal2.c		\
		my_str_to_word_array.c	\
		my_str_to_word_array2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re: fclean all
