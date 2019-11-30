/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** event.c
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

void    Event(sfRenderWindow *window, sfEvent event, coords_t *coords, sprite_t *sprite)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_events(window, event, coords, sprite);
    }
}

void    manage_mouse_click(sfMouseButtonEvent event, coords_t *coords, sfRenderWindow *window, sprite_t *sprite)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x <= coords->x + 68 && mouse.x >= coords->x && mouse.y <= coords->y + 100 && mouse.y >= coords->y && sprite->statut == 0) {
        if (sprite->mode_of_the_game != 2) {
            coords->y = line(line_random());
            coords->x = 1100;
        }
        if (sprite->mode_of_the_game == 1)
            sprite->zombie_deplacement *= 1.2;
        if (sprite->mode_of_the_game == 2) {
            sprite->zombie_deplacement *= 1.2;
            sprite->zombie_heal -= 1;
        }
    }
    if (mouse.x <= coords->x + 68 && mouse.x >= coords->x && mouse.y <= coords->y + 100 && mouse.y >= coords->y && sprite->statut == 2)
        sprite->statut = 0;
    if (mouse.x <= 1100 && mouse.x >= 1000 && mouse.y <= 100 && mouse.y >= 0)
        sprite->statut = 3;
    if (mouse.x <= 935 && mouse.x >= 526 && mouse.y <= 453 && mouse.y >= 354 && sprite->statut == 4)
        sprite->statut = 2;
    if (mouse.x <= 928 && mouse.x >= 529 && mouse.y <= 572 && mouse.y >= 473 && sprite->statut == 4)
        close_windows(window);
    if (mouse.x <= 928 && mouse.x >= 330 && mouse.y <= 328 && mouse.y >= 228 && sprite->statut == 4)
        sprite->statut = 0;
    if (mouse.x <= 508 && mouse.x >= 109 && mouse.y <= 450 && mouse.y >= 351 && sprite->statut == 4) {
        sprite->statut = 0;
        sprite->mode_of_the_game = 1;
    }
    if (mouse.x <= 500 && mouse.x >= 101 && mouse.y <= 571 && mouse.y >= 473 && sprite->statut == 4) {
        sprite->statut = 0;
        sprite->mode_of_the_game = 2;
    }
}

void    analyse_events(sfRenderWindow *window, sfEvent event, coords_t *coords, sprite_t *sprite)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        close_windows(window);

    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, coords, window, sprite);
    if (sfKeyboard_isKeyPressed(sfKeyR) && sprite->statut == 1) {
        sprite->statut = 0;
        sprite->zombie_deplacement = 5;
    }
    if (sfKeyboard_isKeyPressed(sfKeyX) && sprite->volume > 5)
        sprite->volume -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyC))
        sprite->volume += 5;
    if (sfKeyboard_isKeyPressed(sfKeyM) && sprite->statut == 0) 
        sprite->statut = 3;
    if (sfKeyboard_isKeyPressed(sfKeyQ) && sprite->statut == 3)
        sprite->statut = 0;
    if (sfKeyboard_isKeyPressed(sfKeyH))
        sprite->statut = 4;
    sfMusic_setVolume(sprite->music_game, sprite->volume);
}