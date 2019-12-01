/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include "my_hunter.h"
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void    initalise_value(sprite_t *sprite, sfIntRect *rect_zombie)
{
    rect_zombie->left = 0;
    sprite->volume = 100;
    sprite->statut = 4;
    sprite->zombie_deplacement = 5;
    sprite->mode_of_the_game = 0;
    sprite->zombie_heal = 3;
    sprite->score = 0;
    sprite->rect_heal.left = 0;
    sprite->hight_score_easy = 0;
    sprite->hight_score_medium = 0;
    sprite->hight_score_hard = 0;
}

void    display_man(int av, char **ac)
{
    char *text = "retry with ./my_hunter -h";
    char *text1 = "Hello everyone, if you want to kill zombies this game was \
    meant for you.\n\nThe goal is to have the biggest score by killing zombies\
    \n\nyou have 3 lives and you loose 1 each time the zombie touches the \
    character\n\n there are 3 different levels easy/medium and hard\
    \n\nnow good luck if you want more information you have the tutorial";

    if (av != 2 || av == 2 && ac[1][0] != '-'&& ac[1][1] != 'h' \
    && ac[1][2] != '\0')
        write (1, text, 25);
    else
        write(1, text1, 342);
}

int    main(int ac, char **av)
{
    sfRenderWindow *window = windows();
    sfEvent event;
    sfIntRect rect_zombie;
    sfIntRect rect_cursor;
    sprite_t sprite;
    coords_t coords;
    clock_d Clock;

    my_set_sprites(&sprite, &Clock, &coords, window);
    music(&sprite, &rect_zombie, &Clock);
    while (sfRenderWindow_isOpen(window)) {
        if (ac != 1) {
            display_man(ac, av);
            break;
        }
        global_event(window, event, &coords, &sprite);
        my_clock(&rect_zombie, &coords, Clock, &sprite);
        draw_statue(window, &sprite, &coords);
    }
    destroy_sprite(window, sprite);
    return (0);
}