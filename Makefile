##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	*.c	\

NAME	=	my_hunter

OBJ	=	libmy.a

all	:
	gcc -o $(NAME) $(NAME).c -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all