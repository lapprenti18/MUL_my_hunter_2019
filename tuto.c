/*
** EPITECH PROJECT, 2019
** Tek1
** File description:
** my_hunter6.c
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

void    draw_tuto_explication(sprite_t *sprite)
{
    sfVector2f tuto_explication = {0, 0};

    sfText_setString(sprite->text_tuto_explication, "\t\t\tWelcome to my game everyone\n\nwhat is goal ? you see 3 little Karim ? SAVE HIM?!?\n\tNow kill zombie for stat game");
    sfText_setFont(sprite->text_tuto_explication, sprite->font_tuto);
    sfText_setCharacterSize(sprite->text_tuto_explication, 30);
    sfText_setColor(sprite->text_tuto_explication, sfBlue);
    sfText_setPosition(sprite->text_tuto_explication, tuto_explication);
}

void    draw_tuto_life(sprite_t *sprite)
{
    sfVector2f tuto_life = {220, 520};

    sfText_setString(sprite->text_tuto_life, "<- you have 3 life be carefull !");
    sfText_setFont(sprite->text_tuto_life, sprite->font_tuto);
    sfText_setCharacterSize(sprite->text_tuto_life, 40);
    sfText_setColor(sprite->text_tuto_life, sfRed);
    sfText_setPosition(sprite->text_tuto_life, tuto_life);
}

void    draw_tuto_zombie(sprite_t *sprite)
{
    sfVector2f tuto_zombie = {1000, 120};

    sfText_setString(sprite->text_tuto_zombie, "->\n\n\n->\n\n\n\n->");
    sfText_setFont(sprite->text_tuto_zombie, sprite->font_tuto);
    sfText_setCharacterSize(sprite->text_tuto_zombie, 40);
    sfText_setColor(sprite->text_tuto_zombie, sfYellow);
    sfText_setPosition(sprite->text_tuto_zombie, tuto_zombie);
}

void    draw_tuto_zombie_explication(sprite_t *sprite)
{
    sfVector2f tuto_zombie = {520, 260};

    sfText_setString(sprite->text_tuto_zombie_explication, "\t\tzombies will spawn here\n now click on the zombie for kill him");
    sfText_setFont(sprite->text_tuto_zombie_explication, sprite->font_tuto);
    sfText_setCharacterSize(sprite->text_tuto_zombie_explication, 30);
    sfText_setColor(sprite->text_tuto_zombie_explication, sfYellow);
    sfText_setPosition(sprite->text_tuto_zombie_explication, tuto_zombie);
}

void    display_tuto(sprite_t *sprite)
{
    draw_tuto_explication(sprite);
    draw_tuto_life(sprite);
    draw_tuto_zombie(sprite);
    draw_tuto_zombie_explication(sprite);
}