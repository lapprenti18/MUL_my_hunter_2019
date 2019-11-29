/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** statue.c
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

void    draw_statue(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
{
    if (sprite->statut == 0)
        draw_sprite(window, sprite, coords);
    if (sprite->statut == 1)
        draw_game_over(window, sprite, coords);
    if (sprite->statut == 2)
        draw_tuto(window, sprite, coords);
    if (sprite->statut == 3)
        draw_option(window, sprite, coords);
    if (sprite->statut == 4)
        draw_start_menu(window, sprite, coords);
}

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
    \n\nopen setting press ->\n\nclose setting press ->\n\nquit the game press ->";
    char *key = "X\nC\nM\nQ\nm";

    sfText_setString(sprite->text_option_text, text);
    sfText_setFont(sprite->text_option_text, sprite->font_option_text);
    sfText_setCharacterSize(sprite->text_option_text, 20);
    sfText_setColor(sprite->text_option_text, sfBlack);
    sfText_setPosition(sprite->text_option_text, option_text_position);
    sfText_setString(sprite->text_option_key, key);
    sfText_setFont(sprite->text_option_key, sprite->font_option_key);
    sfText_setCharacterSize(sprite->text_option_key, 50);
    sfText_setColor(sprite->text_option_key, sfBlack);
    sfText_setPosition(sprite->text_option_key, option_key_position);
    my_setting(sprite);
}

void    draw_start_menu(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_2 = {mouse.x - 77, mouse.y - 78};

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->menu_start, NULL);
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

void    draw_sprite(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
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
    sfRenderWindow_drawSprite(window, sprite->cursor, NULL);
    sfSprite_setPosition(sprite->cursor, mouse_2);
    sfRenderWindow_display(window);
}

void    display_menu_text(sprite_t *sprite)
{
    sfVector2f game_over_position = {250, 120};

    sfText_setString(sprite->text_game_over, "\t\tgame over  \npress R to restart");
    sfText_setFont(sprite->text_game_over, sprite->font_game_over);
    sfText_setCharacterSize(sprite->text_game_over, 100);
    sfText_setColor(sprite->text_game_over, sfRed);
    sfText_setPosition(sprite->text_game_over, game_over_position);
}

void    draw_game_over(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_2 = {mouse.x - 77, mouse.y - 78};

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->game_over, NULL);
    display_menu_text(sprite);
    sfRenderWindow_drawText(window, sprite->text_game_over, NULL);
    sfSprite_setPosition(sprite->cursor, mouse_2);
    sfRenderWindow_drawSprite(window, sprite->cursor, NULL);
    sfRenderWindow_display(window);
}

sfSprite    *my_backgrd(sfRenderWindow *window)
{
    sfIntRect rect_backgrd;
    sfSprite* backgrd;
    sfTexture* backgrd_texture;
    sfVector2f backgrd_position = {0, 0};

    rect_backgrd.top = 0;
    rect_backgrd.left = 0;
    rect_backgrd.width = 1110;
    rect_backgrd.height = 600;
    backgrd_texture = sfTexture_createFromFile("sprite/backgd.png", NULL);
    backgrd = sfSprite_create();
    sfSprite_setTexture(backgrd, backgrd_texture, sfTrue);
    sfSprite_setTextureRect(backgrd, rect_backgrd);
    sfSprite_setPosition(backgrd, backgrd_position);
    return (backgrd);
}

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
    menu_start_texture = sfTexture_createFromFile("sprite/start_screen.png", NULL);
    menu_start = sfSprite_create();
    sfSprite_setTexture(menu_start, menu_start_texture, sfTrue);
    sfSprite_setTextureRect(menu_start, rect_menu_start);
    sfSprite_setPosition(menu_start, menu_start_position);
    return (menu_start);
}
