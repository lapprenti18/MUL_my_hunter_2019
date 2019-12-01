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

void    music(sprite_t *sprite, sfIntRect *rect_zombie, clock_d *Clock)
{
    Clock->clock = sfClock_create();
    sfMusic_play(sprite->music_game);
    initalise_value(sprite, rect_zombie);
}