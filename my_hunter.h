/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_hunter.h
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

typedef struct my_hunter
{
    int x;
    int y;
} coords_t;

typedef struct sprite_c
{
    sfSprite* zombie;
    sfSprite* cursor;
    sfSprite* backgrd;
    sfSprite* healt;
    sfSprite* karim1;
    sfSprite* karim2;
    sfSprite* karim3;
    sfSprite* game_over;
    sfSprite* option;
    sfSprite* menu_option;
    sfSprite* menu_start;
    sfFont* font_game_over;
    sfFont* font_tuto;
    sfFont* font_option_text;
    sfFont* font_option_key;
    sfText* text_option_text;
    sfText* text_option_key;
    sfText* setting;
    sfText* text_game_over;
    sfText* text_tuto_explication;
    sfText* text_tuto_life;
    sfText* text_tuto_zombie;
    sfText* text_tuto_zombie_explication;
    sfText* display_score;
    sfText* word_score;
    sfText* hg_score_easy;
    sfText* hg_score_medium;
    sfText* hg_score_hard;
    sfText* score_display;
    sfMusic* music_game;
    sfIntRect rect_heal;
    float zombie_deplacement;
    int statut;
    int volume;
    int mode_of_the_game;
    int zombie_heal;
    int score;
    int hight_score_easy;
    int hight_score_medium;
    int hight_score_hard;
    char *char_score;
} sprite_t;

typedef struct clock_t
{
    sfClock *clock;
    sfTime time;
    float second;
} clock_d;

typedef struct all_struct
{
    coords_t coords_t;
    sprite_t sprite_t;
    clock_d clock_d;
} all_struct_t;

void    move_life(sprite_t *sprite, int offset);

void    reset_zombie(coords_t *coords, sprite_t *sprite);

int    line_random(void);

int    line(int line);

void    close_windows(sfRenderWindow *window);

void    manage_mouse_click(sfMouseButtonEvent event, coords_t *coords, \
sfRenderWindow *window, sprite_t *sprite);

void    analyse_events(sfRenderWindow *window, sfEvent event, \
coords_t *coords, sprite_t *sprite);

sfSprite    *my_sprite_sheet_zombie(coords_t *coords);

sfSprite    *my_sprite_sheet_cursor(sfRenderWindow *window);

sfSprite    *my_backgrd(sfRenderWindow *window);

sfSprite    *my_option(sfRenderWindow *window);

sfSprite    *my_game_over(sfRenderWindow *window);

sfSprite    *my_sprite_sheet_health(sfRenderWindow *window);

sfSprite    *my_sprite_sheet_karim1(sfRenderWindow *window);

sfSprite    *my_sprite_sheet_karim2(sfRenderWindow *window);

void    destroy_sprite(sfRenderWindow *window, sprite_t sprite);

sfRenderWindow    *windows(void);

void    my_clock(sfIntRect *rect, coords_t *coords, clock_d clock, \
sprite_t *sprite);

void    move_rect(sfIntRect *rect, int offset, sprite_t *sprite, \
coords_t *coords);

sfSprite    *my_sprite_sheet_karim3(sfRenderWindow *window);

void    draw_game_over(sfRenderWindow *window, sprite_t *sprite, \

coords_t *coords);

void    display_game_over(sprite_t *sprite);

void    my_set_sprites(sprite_t *sprites, clock_d *clock, coords_t *coords, \
sfRenderWindow *window);

void    global_event(sfRenderWindow *window, sfEvent event, coords_t \
*coords, sprite_t *sprite);

void    draw_sprite(sfRenderWindow *window, sprite_t *sprite, coords_t *coords);

void    display_tuto(sprite_t *sprite);

void    draw_tuto_zombie_explication(sprite_t *sprite);

void    draw_tuto_zombie(sprite_t *sprite);

void    draw_tuto_life(sprite_t *sprite);

void    draw_tuto_explication(sprite_t *sprite);

void    display_man(sprite_t *sprite);

void    initalise_value(sprite_t *sprite, sfIntRect *rect_zombie);

void    draw_statue(sfRenderWindow *window, sprite_t *sprite, coords_t *coords);

void    draw_tuto(sfRenderWindow *window, sprite_t *sprite, coords_t *coords);

int    main(int ac, char **av);

sfSprite    *my_menu_option(sfRenderWindow *window);

void    draw_option(sfRenderWindow *window, sprite_t *sprite, coords_t *coords);

void    my_set_sprites2(sprite_t *sprites, clock_d *clock, coords_t *coords, \
sfRenderWindow *window);

void    destroy_sprite2(sfRenderWindow *window, sprite_t sprite);

void    display_help_menu(sprite_t *sprite);

void    my_setting(sprite_t *sprite);

sfSprite    *my_menu_start(sfRenderWindow *window);

void    draw_start_menu(sfRenderWindow *window, sprite_t *sprite, \
coords_t *coords);

void    reset_zombie_easy_meduim(coords_t *coords, sprite_t *sprite);

void    event_click1(sfMouseButtonEvent event, coords_t *coords, \
sfRenderWindow *window, sprite_t *sprite);

void    event_click2(sfMouseButtonEvent event, coords_t *coords, \
sfRenderWindow *window, sprite_t *sprite);

void    key_press(sfRenderWindow *window, sfEvent event, \
coords_t *coords, sprite_t *sprite);

void    reset_zombie_hard(coords_t *coords, sprite_t *sprite);

char *int_to_string(int num);

void    display_score(sprite_t *sprite);

void    display_score_game_over(sprite_t *sprite);

void    display_hg_score(sprite_t *sprite);

void easy(sprite_t *sprite);

void medium(sprite_t *sprite);

void hard(sprite_t *sprite);

void score_display(sprite_t *sprite);

int my_atoi(char *str);

void    register_hg_score(sfRenderWindow *window, sprite_t *sprite);

int    my_strlen(char const *str);