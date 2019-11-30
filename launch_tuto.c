/*
** EPITECH PROJECT, 2019
** Tek1
** File description:
** my_hunter7.c
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

void    draw_tuto(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_2 = {mouse.x - 77, mouse.y - 78};
    sfVector2f zombie_pos = {coords->x, coords->y};

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->backgrd, NULL);
    sfRenderWindow_drawSprite(window, sprite->zombie, NULL);
    sfRenderWindow_drawSprite(window, sprite->healt, NULL);
    sfRenderWindow_drawSprite(window, sprite->karim1, NULL);
    sfRenderWindow_drawSprite(window, sprite->karim2, NULL);
    sfRenderWindow_drawSprite(window, sprite->karim3, NULL);
    display_tuto(sprite);
    sfRenderWindow_drawText(window, sprite->text_tuto_explication, NULL);
    sfRenderWindow_drawText(window, sprite->text_tuto_life, NULL);
    sfRenderWindow_drawText(window, sprite->text_tuto_zombie, NULL);
    sfRenderWindow_drawText(window, sprite->text_tuto_zombie_explication, \
    NULL);
    sfRenderWindow_drawSprite(window, sprite->cursor, NULL);
    sfSprite_setPosition(sprite->cursor, mouse_2);
    sfRenderWindow_display(window);
}