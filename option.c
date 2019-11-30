/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** option.c
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

sfSprite    *my_option(sfRenderWindow *window)
{
    sfIntRect rect_option;
    sfSprite* option;
    sfTexture* option_texture;
    sfVector2f option_position = {1000, 0};

    rect_option.top = 700;
    rect_option.left = 0;
    rect_option.width = 100;
    rect_option.height = 100;
    option_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    option = sfSprite_create();
    sfSprite_setTexture(option, option_texture, sfTrue);
    sfSprite_setTextureRect(option, rect_option);
    sfSprite_setPosition(option, option_position);
    return (option);
}

sfSprite    *my_menu_option(sfRenderWindow *window)
{
    sfIntRect rect_menu_option;
    sfSprite* menu_option;
    sfTexture* menu_option_texture;
    sfVector2f menu_option_position = {400, 0};

    rect_menu_option.top = 715;
    rect_menu_option.left = 1140;
    rect_menu_option.width = 446;
    rect_menu_option.height = 471;
    menu_option_texture = sfTexture_createFromFile\
    ("sprite/zombie_sheet.png", NULL);
    menu_option = sfSprite_create();
    sfSprite_setTexture(menu_option, menu_option_texture, sfTrue);
    sfSprite_setTextureRect(menu_option, rect_menu_option);
    sfSprite_setPosition(menu_option, menu_option_position);
    return (menu_option);
}