/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** sprite_start.c
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

sfSprite    *my_menu_start(sfRenderWindow *window)
{
    sfIntRect rect_menu_start;
    sfSprite* menu_start;
    sfTexture* menu_start_texture;
    sfVector2f menu_start_position = {0, 0};

    rect_menu_start.top = 0;
    rect_menu_start.left = 0;
    rect_menu_start.width = 1110;
    rect_menu_start.height = 600;
    menu_start_texture = sfTexture_createFromFile\
    ("sprite/start_screen.png", NULL);
    menu_start = sfSprite_create();
    sfSprite_setTexture(menu_start, menu_start_texture, sfTrue);
    sfSprite_setTextureRect(menu_start, rect_menu_start);
    sfSprite_setPosition(menu_start, menu_start_position);
    return (menu_start);
}
