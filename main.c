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

void    display_man(sprite_t *sprite)
{
    sprite->statut = 2;
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
    Clock.clock = sfClock_create();
    sfMusic_play(sprite.music_game);
    initalise_value(&sprite, &rect_zombie);
    if (ac == 2)
        display_man(&sprite);
    while (sfRenderWindow_isOpen(window)) {
        global_event(window, event, &coords, &sprite);
        my_clock(&rect_zombie, &coords, Clock, &sprite);
        draw_statue(window, &sprite, &coords);
    }
    destroy_sprite(window, sprite);
    return (0);
}