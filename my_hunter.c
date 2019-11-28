/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
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

void    move_life(sprite_t *sprite, int offset)
{
    sprite->rect_heal.top = 323;
    sprite->rect_heal.left += offset;
    sprite->rect_heal.width = 215.5;
    sprite->rect_heal.height = 68;
    if (sprite->rect_heal.left >= 645) {
        sprite->statut = 1;
        sprite->rect_heal.left = 1;
    }
    sfSprite_setTextureRect(sprite->healt, sprite->rect_heal);
}

void    reset_zombie(coords_t *coords, sprite_t *sprite)
{
    if (sprite->statut == 0) {
        if (coords->y == 442 && coords->x < 123) {
            coords->x = 1110;
            coords->y = coords->y - 165;
            move_life(sprite, 215.5);
        }
        if (coords->y == 277 && coords->x < 354){
            coords->x = 1110;
            coords->y = coords->y - 165;
            move_life(sprite, 215.5);
        }
        if (coords->y == 112 && coords->x < 639) {
            coords->x = 1110;
            coords->y = 442;
            move_life(sprite, 215.5);
        } else
            coords->x -= 15;
    }
}

int    line_random(void)
{
    int nbgen;
    srand(time(NULL));
    return (nbgen=rand()%3+0);
}

int    line(int line)
{
    if (line == 0)
        return (442);
    if (line == 1)
        return (277);
    if (line == 2)
        return (112);
}

void    close_windows(sfRenderWindow *window)
{
        sfRenderWindow_close(window);
}

void    manage_mouse_click(sfMouseButtonEvent event, coords_t *coords, sfRenderWindow *window, sprite_t *sprite)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x <= coords->x + 68 && mouse.x >= coords->x && mouse.y <= coords->y + 100 && mouse.y >= coords->y) {
        coords->x = 1100;
        coords->y = line(line_random());
    }
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

sfSprite    *my_sprite_sheet_zombie(coords_t *coords)
{
    sfSprite* zombie;
    sfTexture* zombie_texture;
    sfIntRect rect;
    sfVector2f pos = {coords->x, coords->y};

    rect.top = 200;
    rect.width = 68;
    rect.height = 100;
    rect.left = 0;
    zombie_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    zombie = sfSprite_create();
    sfSprite_setTexture(zombie, zombie_texture, sfTrue);
    sfSprite_setTextureRect(zombie, rect);
    sfSprite_setPosition(zombie, pos);
    return (zombie);
}

sfSprite    *my_sprite_sheet_cursor(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* cursor;
    sfTexture* cursor_texture;
    sfVector2f cursor_position;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    cursor_position.x = mouse.x - 77;
    cursor_position.y = mouse.y - 78;
    rect.top = 360;
    rect.left = 1025;
    rect.width = 200;
    rect.height = 200;
    cursor_texture = sfTexture_createFromFile("sprite/cursor.png", NULL);
    cursor = sfSprite_create();
    sfSprite_setTexture(cursor, cursor_texture, sfTrue);
    sfSprite_setTextureRect(cursor, rect);
    sfSprite_setPosition(cursor, cursor_position);
    return (cursor);
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

sfSprite    *my_game_over(sfRenderWindow *window)
{
    sfIntRect rect_game_over;
    sfSprite* game_over;
    sfTexture* game_over_texture;
    sfVector2f game_over_position = {0, 0};

    rect_game_over.top = 0;
    rect_game_over.left = 0;
    rect_game_over.width = 1110;
    rect_game_over.height = 600;
    game_over_texture = sfTexture_createFromFile("sprite/backgd_gameover.png", NULL);
    game_over = sfSprite_create();
    sfSprite_setTexture(game_over, game_over_texture, sfTrue);
    sfSprite_setTextureRect(game_over, rect_game_over);
    sfSprite_setPosition(game_over, game_over_position);
    return (game_over);
}

sfSprite    *my_sprite_sheet_health(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* health;
    sfTexture* health_texture;
    sfVector2f health_position = {0, 510};

    rect.top = 323;
    rect.left = 1;
    rect.width = 215.5;
    rect.height = 68;
    health_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    health = sfSprite_create();
    sfSprite_setTexture(health, health_texture, sfTrue);
    sfSprite_setTextureRect(health, rect);
    sfSprite_setPosition(health, health_position);
    return (health);
}

sfSprite    *my_sprite_sheet_karim1(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* karim1;
    sfTexture* karim1_texture;
    sfVector2f karim1_position = {80, 407};

    rect.top = 450;
    rect.left = 1;
    rect.width = 90;
    rect.height = 125;
    karim1_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    karim1 = sfSprite_create();
    sfSprite_setTexture(karim1, karim1_texture, sfTrue);
    sfSprite_setTextureRect(karim1, rect);
    sfSprite_setPosition(karim1, karim1_position);
    return (karim1);
}

sfSprite    *my_sprite_sheet_karim2(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* karim2;
    sfTexture* karim2_texture;
    sfVector2f karim2_position = {300, 240};

    rect.top = 450;
    rect.left = 1;
    rect.width = 90;
    rect.height = 125;
    karim2_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    karim2 = sfSprite_create();
    sfSprite_setTexture(karim2, karim2_texture, sfTrue);
    sfSprite_setTextureRect(karim2, rect);
    sfSprite_setPosition(karim2, karim2_position);
    return (karim2);
}

sfSprite    *my_sprite_sheet_karim3(sfRenderWindow *window)
{
    sfIntRect rect;
    sfSprite* karim3;
    sfTexture* karim3_texture;
    sfVector2f karim3_position = {580, 75};

    rect.top = 450;
    rect.left = 1;
    rect.width = 90;
    rect.height = 125;
    karim3_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    karim3 = sfSprite_create();
    sfSprite_setTexture(karim3, karim3_texture, sfTrue);
    sfSprite_setTextureRect(karim3, rect);
    sfSprite_setPosition(karim3, karim3_position);
    return (karim3);
}


void    move_rect(sfIntRect *rect, int offset, sprite_t *sprite, coords_t *coords)
{
    sfVector2f pos = {coords->x, coords->y};

    rect->top = 200;
    rect->left += offset;
    rect->width = 68;
    rect->height = 100;
    if (rect->left > 1100)
        rect->left = 544;
    reset_zombie(coords, sprite);
    sfSprite_setPosition(sprite->zombie, pos);
    sfSprite_setTextureRect(sprite->zombie, *rect);
}


void    my_clock(sfIntRect *rect, coords_t *coords, clock_d clock, sprite_t *sprite)
{
    while (clock.second < 0.05)
    {
        clock.time = sfClock_getElapsedTime(clock.clock);
        clock.second = clock.time.microseconds/1000000.0;
    }
    sfClock_restart(clock.clock);
    move_rect(rect, 68, sprite, coords);
}

sfRenderWindow    *windows(void)
{
    sfRenderWindow* window;
    sfVideoMode mode = {1110, 600, 32};

    window = sfRenderWindow_create(mode, "SFML window", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    return (window);
}

void    destroy_sprite(sfRenderWindow *window, sprite_t sprite)
{
    sfSprite_destroy(sprite.zombie);
    sfSprite_destroy(sprite.cursor);
    sfSprite_destroy(sprite.backgrd);
    sfSprite_destroy(sprite.game_over);
    sfSprite_destroy(sprite.healt);
    sfSprite_destroy(sprite.karim1);
    sfSprite_destroy(sprite.karim2);
    sfSprite_destroy(sprite.karim3);
    sfMusic_destroy(sprite.music_game);
    sfFont_destroy(sprite.font);
    sfText_destroy(sprite.text);
    sfRenderWindow_destroy(window);
}

void    draw_sprite(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_2 = {mouse.x - 77, mouse.y - 78};
    sfVector2f zombie_pos = {coords->x, coords->y};

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->backgrd, NULL);
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

void    Event(sfRenderWindow *window, sfEvent event, coords_t *coords, sprite_t *sprite)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_events(window, event, coords, sprite);
    }
}

void    my_set_sprites(sprite_t *sprites, clock_d *clock, coords_t *coords, sfRenderWindow *window)
{
    clock->second = 0;
    coords->x = 1050;
    coords->y = line(line_random());
    sprites->backgrd = my_backgrd(window);
    sprites->game_over = my_game_over(window);
    sprites->zombie = my_sprite_sheet_zombie(coords);
    sprites->cursor = my_sprite_sheet_cursor(window);
    sprites->healt = my_sprite_sheet_health(window);
    sprites->karim1 = my_sprite_sheet_karim1(window);
    sprites->karim2 = my_sprite_sheet_karim2(window);
    sprites->karim3 = my_sprite_sheet_karim3(window);
    sprites->music_game = sfMusic_createFromFile("sprite/playing.ogg");
}

void    display_game_over(sprite_t *sprite)
{
    sfVector2f game_over_position = {250, 120};

    sprite->font = sfFont_createFromFile("sprite/Madjoe.ttf");
    sprite->text = sfText_create();
    sfText_setString(sprite->text, "\tgame over  \npress R to restart");
    sfText_setFont(sprite->text, sprite->font);
    sfText_setCharacterSize(sprite->text, 100);
    sfText_setColor(sprite->text, sfRed);
    sfText_setPosition(sprite->text, game_over_position);
}

void    draw_game_over(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_2 = {mouse.x - 77, mouse.y - 78};

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->game_over, NULL);
    sfRenderWindow_drawSprite(window, sprite->cursor, NULL);
    sfSprite_setPosition(sprite->cursor, mouse_2);
    display_game_over(sprite);
    sfRenderWindow_drawText(window, sprite->text, NULL);
    sfRenderWindow_display(window);
}

void    draw_statue(sfRenderWindow *window, sprite_t *sprite, coords_t *coords)
{
    if (sprite->statut == 0)
        draw_sprite(window, sprite, coords);
    if (sprite->statut == 1)
        draw_game_over(window, sprite, coords);
    //if (sprite->statut == 2)
    //    draw_tuto();
}

void    initalise_value(sprite_t *sprite, sfIntRect *rect_zombie)
{
    rect_zombie->left = 0;
    sprite->volume = 100;
    sprite->statut = 0;
}

void    display_man(sprite_t *sprite)
{
    sprite->statut = 1;
}

int    main(int ac, char **av)
{
    sfRenderWindow *window = windows();
    sfEvent event;
    sfIntRect rect_zombie;
    sfIntRect rect_cursor;
    sprite_t sprite;
    coords_t coords;
    clock_d Clock;

    my_set_sprites(&sprite, &Clock, &coords, window);
    Clock.clock = sfClock_create();
    sfMusic_play(sprite.music_game);
    initalise_value(&sprite, &rect_zombie);
    if (ac == 2)
        display_man(&sprite);
    while (sfRenderWindow_isOpen(window)) {
        Event(window, event, &coords, &sprite);
        my_clock(&rect_zombie, &coords, Clock, &sprite);
        draw_statue(window, &sprite, &coords);
    }
    destroy_sprite(window, sprite);
    return (0);
}