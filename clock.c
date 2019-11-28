/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** clock.c
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

void    move_rect(sfIntRect *rect, int offset, sprite_t *sprite, coords_t *coords)
{
    sfVector2f pos = {coords->x, coords->y};

    rect->top = 200;
    rect->left += offset;
    rect->width = 68;
    rect->height = 100;
    if (rect->left > 1100)
        rect->left = 544;
    reset_zombie(coords, sprite);
    sfSprite_setPosition(sprite->zombie, pos);
    sfSprite_setTextureRect(sprite->zombie, *rect);
}


void    my_clock(sfIntRect *rect, coords_t *coords, clock_d clock, sprite_t *sprite)
{
    while (clock.second < 0.05)
    {
        clock.time = sfClock_getElapsedTime(clock.clock);
        clock.second = clock.time.microseconds/1000000.0;
    }
    sfClock_restart(clock.clock);
    move_rect(rect, 68, sprite, coords);
}