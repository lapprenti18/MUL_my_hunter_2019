/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** analyse_event.c
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

void    analyse_events(sfRenderWindow *window, sfEvent event, \
coords_t *coords, sprite_t *sprite)
{
    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        close_windows(window);

    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, coords, window, sprite);
    if (event.key.code == sfKeyR && sprite->statut == 1) {
        sprite->statut = 0;
        sprite->zombie_deplacement = 5;
        sprite->score = 0;
    }
    key_press(window, event, coords, sprite);
    sfMusic_setVolume(sprite->music_game, sprite->volume);
}