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

void    display_menu_text(sprite_t *sprite)
{
    sfVector2f game_over_position = {250, 120};
    char *text = "\t\tgame over  \npress R to restart";

    sfText_setString(sprite->text_game_over, text);
    sfText_setFont(sprite->text_game_over, sprite->font_game_over);
    sfText_setCharacterSize(sprite->text_game_over, 100);
    sfText_setColor(sprite->text_game_over, sfRed);
    sfText_setPosition(sprite->text_game_over, game_over_position);
}

void    display_score_game_over(sprite_t *sprite)
{
    sfVector2f score_position = {550, 320};
    sfVector2f word_position = {250, 320};
    char *text = int_to_string(sprite->score);
    char *word = "score :";

    sprite->char_score = int_to_string(sprite->score);
    sfText_setString(sprite->display_score, text);
    sfText_setFont(sprite->display_score, sprite->font_option_text);
    sfText_setCharacterSize(sprite->display_score, 100);
    sfText_setColor(sprite->display_score, sfYellow);
    sfText_setPosition(sprite->display_score, score_position);

    sfText_setString(sprite->word_score, word);
    sfText_setFont(sprite->word_score, sprite->font_option_text);
    sfText_setCharacterSize(sprite->word_score, 100);
    sfText_setColor(sprite->word_score, sfYellow);
    sfText_setPosition(sprite->word_score, word_position);
}

void    draw_game_over(sfRenderWindow *window, sprite_t *sprite, \
coords_t *coords)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_2 = {mouse.x - 77, mouse.y - 78};

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->game_over, NULL);
    display_menu_text(sprite);
    sfRenderWindow_drawText(window, sprite->text_game_over, NULL);
    sfSprite_setPosition(sprite->cursor, mouse_2);
    display_score_game_over(sprite);
    sfRenderWindow_drawText(window, sprite->display_score, NULL);
    sfRenderWindow_drawText(window, sprite->word_score, NULL);
    sfRenderWindow_drawSprite(window, sprite->cursor, NULL);
    register_hg_score(window, sprite);
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