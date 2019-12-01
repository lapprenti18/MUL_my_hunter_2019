/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** sprite.c
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

void    destroy_sprite2(sfRenderWindow *window, sprite_t sprite)
{
    sfText_destroy(sprite.text_tuto_explication);
    sfText_destroy(sprite.text_tuto_life);
    sfText_destroy(sprite.text_tuto_zombie);
    sfText_destroy(sprite.text_tuto_zombie_explication);
    sfText_destroy(sprite.setting);
    sfText_destroy(sprite.display_score);
    sfText_destroy(sprite.word_score);
    sfText_destroy(sprite.hg_score_easy);
    sfText_destroy(sprite.hg_score_medium);
    sfText_destroy(sprite.hg_score_hard);
    sfText_destroy(sprite.score_display);
}

void    destroy_sprite(sfRenderWindow *window, sprite_t sprite)
{
    sfSprite_destroy(sprite.zombie);
    sfSprite_destroy(sprite.cursor);
    sfSprite_destroy(sprite.backgrd);
    sfSprite_destroy(sprite.option);
    sfSprite_destroy(sprite.game_over);
    sfSprite_destroy(sprite.healt);
    sfSprite_destroy(sprite.karim1);
    sfSprite_destroy(sprite.karim2);
    sfSprite_destroy(sprite.karim3);
    sfSprite_destroy(sprite.menu_option);
    sfSprite_destroy(sprite.menu_start);
    sfMusic_destroy(sprite.music_game);
    sfFont_destroy(sprite.font_game_over);
    sfText_destroy(sprite.text_game_over);
    sfFont_destroy(sprite.font_tuto);
    destroy_sprite2(window, sprite);
    sfRenderWindow_destroy(window);
}

void    my_set_sprites2(sprite_t *sprites, clock_d *clock, \
coords_t *coords, sfRenderWindow *window)
{
    sprites->text_game_over = sfText_create();
    sprites->music_game = sfMusic_createFromFile("sprite/playing.ogg");
    sprites->font_option_key = sfFont_createFromFile\
    ("sprite/212-Keyboard.ttf");
    sprites->text_option_key = sfText_create();
    sprites->font_option_text = sfFont_createFromFile\
    ("sprite/Kid-Knowledge-1.ttf");
    sprites->text_option_text = sfText_create();
    sprites->setting = sfText_create();
    sprites->text_tuto_zombie = sfText_create();
    sprites->text_tuto_zombie_explication = sfText_create();
    sprites->display_score = sfText_create();
    sprites->word_score = sfText_create();
    sprites->hg_score_easy = sfText_create();
    sprites->hg_score_medium = sfText_create();
    sprites->hg_score_hard = sfText_create();
    sprites->score_display = sfText_create();
}

void    my_set_sprites(sprite_t *sprites, clock_d *clock, coords_t *coords, \
sfRenderWindow *window)
{
    clock->second = 0;
    coords->x = 1050;
    coords->y = line(line_random());
    sprites->backgrd = my_backgrd(window);
    sprites->menu_start = my_menu_start(window);
    sprites->option = my_option(window);
    sprites->game_over = my_game_over(window);
    sprites->zombie = my_sprite_sheet_zombie(coords);
    sprites->cursor = my_sprite_sheet_cursor(window);
    sprites->healt = my_sprite_sheet_health(window);
    sprites->karim1 = my_sprite_sheet_karim1(window);
    sprites->karim2 = my_sprite_sheet_karim2(window);
    sprites->karim3 = my_sprite_sheet_karim3(window);
    sprites->menu_option = my_menu_option(window);
    sprites->font_tuto = sfFont_createFromFile\
    ("sprite/the_day_is_my_enemy.ttf");
    sprites->font_game_over = sfFont_createFromFile("sprite/Madjoe.ttf");
    sprites->text_tuto_explication = sfText_create();
    sprites->text_tuto_life = sfText_create();
    my_set_sprites2(sprites, clock, coords, window);
}