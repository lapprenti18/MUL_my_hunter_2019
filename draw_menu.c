/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** draw_menu.c
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

void    my_setting(sprite_t *sprite)
{
    sfVector2f setting_position = {460, 15};
    char *setting = "Setting & pause";

    sfText_setString(sprite->setting, setting);
    sfText_setFont(sprite->setting, sprite->font_option_text);
    sfText_setCharacterSize(sprite->setting, 50);
    sfText_setColor(sprite->setting, sfBlack);
    sfText_setPosition(sprite->setting, setting_position);

}

void    display_help_menu(sprite_t *sprite)
{
    sfVector2f option_text_position = {480, 150};
    sfVector2f option_key_position = {670, 120};
    char *text = "volume down press ->\n\nvolume up press ->\
    \n\nopen setting press ->\n\nclose setting press ->\
    \n\nquit the game press ->\
    \n\n\nback to home press ->";
    char *key = "X\nC\nM\nQ\nm\nH";

    sfText_setString(sprite->text_option_text, text);
    sfText_setFont(sprite->text_option_text, sprite->font_option_text);
    sfText_setCharacterSize(sprite->text_option_text, 20);
    sfText_setColor(sprite->text_option_text, sfBlack);
    sfText_setPosition(sprite->text_option_text, option_text_position);
    sfText_setString(sprite->text_option_key, key);
    sfText_setFont(sprite->text_option_key, sprite->font_option_key);
    sfText_setCharacterSize(sprite->text_option_key, 50);
    sfText_setColor(sprite->text_option_key, sfWhite);
    sfText_setPosition(sprite->text_option_key, option_key_position);
    my_setting(sprite);
}

void    draw_start_menu(sfRenderWindow *window, sprite_t *sprite, \
coords_t *coords)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_2 = {mouse.x - 77, mouse.y - 78};

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->menu_start, NULL);
    display_hg_score(sprite);
    sfRenderWindow_drawText(window, sprite->hg_score_easy, NULL);
    sfRenderWindow_drawText(window, sprite->hg_score_medium, NULL);
    sfRenderWindow_drawText(window, sprite->hg_score_hard, NULL);
    sfRenderWindow_drawText(window, sprite->score_display, NULL);
    sfRenderWindow_drawSprite(window, sprite->cursor, NULL);
    sfSprite_setPosition(sprite->cursor, mouse_2);
    sfRenderWindow_display(window);
}

void    draw_option(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_2 = {mouse.x - 77, mouse.y - 78};
    sfVector2f zombie_pos = {coords->x, coords->y};

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->backgrd, NULL);
    sfRenderWindow_drawSprite(window, sprite->option, NULL);
    sfRenderWindow_drawSprite(window, sprite->zombie, NULL);
    sfSprite_setPosition(sprite->zombie, zombie_pos);
    sfRenderWindow_drawSprite(window, sprite->healt, NULL);
    sfRenderWindow_drawSprite(window, sprite->karim1, NULL);
    sfRenderWindow_drawSprite(window, sprite->karim2, NULL);
    sfRenderWindow_drawSprite(window, sprite->karim3, NULL);
    sfRenderWindow_drawSprite(window, sprite->menu_option, NULL);
    display_help_menu(sprite);
    sfRenderWindow_drawText(window, sprite->text_option_text, NULL);
    sfRenderWindow_drawText(window, sprite->text_option_key, NULL);
    sfRenderWindow_drawText(window, sprite->setting, NULL);
    sfRenderWindow_drawSprite(window, sprite->cursor, NULL);
    sfSprite_setPosition(sprite->cursor, mouse_2);
    sfRenderWindow_display(window);
}