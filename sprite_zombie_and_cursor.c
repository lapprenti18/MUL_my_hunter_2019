/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** sprite_zombie.c
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

void    reset_zombie(coords_t *coords, sprite_t *sprite)
{
    if (sprite->statut == 0) {
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
            coords->x -= 15;
    }
}

int    line_random(void)
{
    int nbgen;
    srand(time(NULL));
    return (nbgen=rand()%3+0);
}

int    line(int line)
{
    if (line == 0)
        return (442);
    if (line == 1)
        return (277);
    if (line == 2)
        return (112);
}

sfSprite    *my_sprite_sheet_zombie(coords_t *coords)
{
    sfSprite* zombie;
    sfTexture* zombie_texture;
    sfIntRect rect;
    sfVector2f pos = {coords->x, coords->y};

    rect.top = 200;
    rect.width = 68;
    rect.height = 100;
    rect.left = 0;
    zombie_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    zombie = sfSprite_create();
    sfSprite_setTexture(zombie, zombie_texture, sfTrue);
    sfSprite_setTextureRect(zombie, rect);
    sfSprite_setPosition(zombie, pos);
    return (zombie);
}

sfSprite    *my_sprite_sheet_cursor(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* cursor;
    sfTexture* cursor_texture;
    sfVector2f cursor_position;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    cursor_position.x = mouse.x - 77;
    cursor_position.y = mouse.y - 78;
    rect.top = 360;
    rect.left = 1025;
    rect.width = 200;
    rect.height = 200;
    cursor_texture = sfTexture_createFromFile("sprite/cursor.png", NULL);
    cursor = sfSprite_create();
    sfSprite_setTexture(cursor, cursor_texture, sfTrue);
    sfSprite_setTextureRect(cursor, rect);
    sfSprite_setPosition(cursor, cursor_position);
    return (cursor);
}