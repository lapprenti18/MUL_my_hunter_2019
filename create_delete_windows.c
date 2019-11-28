/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** create_delete_windows.c
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

sfRenderWindow    *windows(void)
{
    sfRenderWindow* window;
    sfVideoMode mode = {1110, 600, 32};

    window = sfRenderWindow_create(mode, "SFML window", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    return (window);
}

void    close_windows(sfRenderWindow *window)
{
        sfRenderWindow_close(window);
}