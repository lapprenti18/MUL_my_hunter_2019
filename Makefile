##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	clock.c	\
		create_delete_windows.c	\
		destroye_and_set.c	\
		event.c	\
		game_over.c	\
		launch_tuto.c	\
		main.c	\
		option.c	\
		sprite_game.c	\
		sprite_zombie_and_cursor.c	\
		statue.c	\
		tuto.c	\
		draw_menu.c	\
		reset_zomb.c	\
		sprite_start.c	\
		analyse_event.c	\
		int_to_string.c	\
		read_best_score.c	\
		high_score.c	\
		statut_menu.c	\

NAME	=	my_hunter

OBJ	=	libmy.a

all	:
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all