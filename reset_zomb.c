/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** reset_zomb.c
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

void    reset_zombie_easy_meduim(coords_t *coords, sprite_t *sprite)
{
    if (coords->y == 442 && coords->x < 123) {
            coords->x = 1110;
            coords->y = coords->y - 165;
            move_life(sprite, 215.5);
    }
    if (coords->y == 277 && coords->x < 354){
            coords->x = 1110;
            coords->y = coords->y - 165;
            move_life(sprite, 215.5);
    }
    if (coords->y == 112 && coords->x < 639) {
            coords->x = 1110;
            coords->y = 442;
            move_life(sprite, 215.5);
    } else
        coords->x -= sprite->zombie_deplacement;
}

void    reset_zombie_hard(coords_t *coords, sprite_t *sprite)
{
    if (sprite->zombie_heal != 0) {
        if (coords->y == 442 && coords->x < 123) {
                coords->x = 1110;
                coords->y = coords->y - 165;
                move_life(sprite, 215.5);
        }
        if (coords->y == 277 && coords->x < 354){
                coords->x = 1110;
                coords->y = coords->y - 165;
                move_life(sprite, 215.5);
        }
        if (coords->y == 112 && coords->x < 639) {
                coords->x = 1110;
                coords->y = 442;
                move_life(sprite, 215.5);
        } else {
            coords->x -= sprite->zombie_deplacement;
            }
    } else {
        sprite->zombie_heal = 3;
        coords->x = 1100;
        coords->y = line(line_random());
    }
}

void    reset_zombie(coords_t *coords, sprite_t *sprite)
{
    if (sprite->statut == 0) {
        if (sprite->mode_of_the_game != 2) {
            reset_zombie_easy_meduim(coords, sprite);
        } else
        reset_zombie_hard(coords, sprite);
    }
}