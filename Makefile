##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	$(realpath ./src)

SRC_LIB		=	$(realpath ./lib/my)

SRC		=	$(SRC_DIR)/main.c	\
			$(SRC_DIR)/execute.c	\
			$(SRC_DIR)/init_list.c	\
			$(SRC_DIR)/shell1_functions.c	\
			$(SRC_DIR)/shell1_functions2.c	\

CFLAGS		=	-W -Wall -I./include

LIB		=	-L./lib/my -lmy

NAME		=	mysh

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(SRC_LIB)
		gcc -o $(NAME) $(SRC) $(LIB) $(CFLAGS)

debug:		$(OBJ)
		make -C $(SRC_LIB)
		gcc -o $(NAME) $(SRC) $(LIB) $(CFLAGS) -g3

clean:
		make clean -C $(SRC_LIB)
		rm -f $(OBJ)
		rm -f $(SRC_DIR)/*~

fclean:		clean
		make fclean -C $(SRC_LIB)
		rm -f $(NAME)

re:		fclean all

.PHONY:		all debug clean fclean re

