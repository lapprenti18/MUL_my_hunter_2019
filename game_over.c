/*
** EPITECH PROJECT, 2019
** Tek1
** File description:
** my_hunter3.c
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

sfSprite    *my_game_over(sfRenderWindow *window)
{
    sfIntRect rect_game_over;
    sfSprite* game_over;
    sfTexture* game_over_texture;
    sfVector2f game_over_position = {0, 0};

    rect_game_over.top = 0;
    rect_game_over.left = 0;
    rect_game_over.width = 1110;
    rect_game_over.height = 600;
    game_over_texture = sfTexture_createFromFile("sprite/backgd_gameover.png", NULL);
    game_over = sfSprite_create();
    sfSprite_setTexture(game_over, game_over_texture, sfTrue);
    sfSprite_setTextureRect(game_over, rect_game_over);
    sfSprite_setPosition(game_over, game_over_position);
    return (game_over);
}