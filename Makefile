##
## EPITECH PROJECT, 2019
## Piscine_C_J10
## File description:
## Makefile
##

.PHONY : all clean fclean re

SRC	=	infin_add.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all:	$(OBJ)
##	make -sC ../lib/my
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
