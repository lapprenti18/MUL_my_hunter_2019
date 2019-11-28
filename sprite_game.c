/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** sprite_game.c
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

sfSprite    *my_sprite_sheet_karim1(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* karim1;
    sfTexture* karim1_texture;
    sfVector2f karim1_position = {80, 407};

    rect.top = 450;
    rect.left = 1;
    rect.width = 90;
    rect.height = 125;
    karim1_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    karim1 = sfSprite_create();
    sfSprite_setTexture(karim1, karim1_texture, sfTrue);
    sfSprite_setTextureRect(karim1, rect);
    sfSprite_setPosition(karim1, karim1_position);
    return (karim1);
}

sfSprite    *my_sprite_sheet_karim2(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* karim2;
    sfTexture* karim2_texture;
    sfVector2f karim2_position = {300, 240};

    rect.top = 450;
    rect.left = 1;
    rect.width = 90;
    rect.height = 125;
    karim2_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    karim2 = sfSprite_create();
    sfSprite_setTexture(karim2, karim2_texture, sfTrue);
    sfSprite_setTextureRect(karim2, rect);
    sfSprite_setPosition(karim2, karim2_position);
    return (karim2);
}

sfSprite    *my_sprite_sheet_karim3(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* karim3;
    sfTexture* karim3_texture;
    sfVector2f karim3_position = {580, 75};

    rect.top = 450;
    rect.left = 1;
    rect.width = 90;
    rect.height = 125;
    karim3_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    karim3 = sfSprite_create();
    sfSprite_setTexture(karim3, karim3_texture, sfTrue);
    sfSprite_setTextureRect(karim3, rect);
    sfSprite_setPosition(karim3, karim3_position);
    return (karim3);
}

sfSprite    *my_sprite_sheet_health(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* health;
    sfTexture* health_texture;
    sfVector2f health_position = {0, 510};

    rect.top = 323;
    rect.left = 1;
    rect.width = 215.5;
    rect.height = 68;
    health_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    health = sfSprite_create();
    sfSprite_setTexture(health, health_texture, sfTrue);
    sfSprite_setTextureRect(health, rect);
    sfSprite_setPosition(health, health_position);
    return (health);
}

void    move_life(sprite_t *sprite, int offset)
{
    sprite->rect_heal.top = 323;
    sprite->rect_heal.left += offset;
    sprite->rect_heal.width = 215.5;
    sprite->rect_heal.height = 68;
    if (sprite->rect_heal.left >= 645) {
        sprite->statut = 1;
        sprite->rect_heal.left = 1;
    }
    sfSprite_setTextureRect(sprite->healt, sprite->rect_heal);
}