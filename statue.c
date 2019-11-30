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

void    display_score(sprite_t *sprite)
{
    sfVector2f score_position = {1070, 520};
    sfVector2f word_position = {950, 520};
    char *text = int_to_string(sprite->score);
    char *word = "score :";

    printf("score1 = %d\n", sprite->score);
    printf("score2 =%s\n", int_to_string(sprite->score));
    sfText_setString(sprite->display_score, text);
    sfText_setFont(sprite->display_score, sprite->font_option_text);
    sfText_setCharacterSize(sprite->display_score, 40);
    sfText_setColor(sprite->display_score, sfRed);
    sfText_setPosition(sprite->display_score, score_position);

    sfText_setString(sprite->word_score, word);
    sfText_setFont(sprite->word_score, sprite->font_option_text);
    sfText_setCharacterSize(sprite->word_score, 40);
    sfText_setColor(sprite->word_score, sfRed);
    sfText_setPosition(sprite->word_score, word_position);
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
    display_score(sprite);
    sfRenderWindow_drawText(window, sprite->display_score, NULL);
    sfRenderWindow_drawText(window, sprite->word_score, NULL);
    sfRenderWindow_drawSprite(window, sprite->cursor, NULL);
    sfSprite_setPosition(sprite->cursor, mouse_2);
    sfRenderWindow_display(window);
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

    printf("score1 = %d\n", sprite->score);
    printf("score2 =%s\n", int_to_string(sprite->score));
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