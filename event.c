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
        coords->x = 1100;
        coords->y = line(line_random());
    }
    if (mouse.x <= coords->x + 68 && mouse.x >= coords->x && mouse.y <= coords->y + 100 && mouse.y >= coords->y && sprite->statut == 2)
        sprite->statut = 0;
    if (mouse.x <= 1100 && mouse.x >= 1000 && mouse.y <= 100 && mouse.y >= 0)
        sprite->statut = 2;
}

void    analyse_events(sfRenderWindow *window, sfEvent event, coords_t *coords, sprite_t *sprite)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        close_windows(window);

    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, coords, window, sprite);
    if (sfKeyboard_isKeyPressed(sfKeyR) && sprite->statut == 1)
        sprite->statut = 0;
    if (sfKeyboard_isKeyPressed(sfKeyX) && sprite->volume > 5)
        sprite->volume -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyC))
        sprite->volume += 5;
    sfMusic_setVolume(sprite->music_game, sprite->volume);
}