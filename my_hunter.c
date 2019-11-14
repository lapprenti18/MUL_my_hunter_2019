/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include "my_hunter.h"
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void    close_windows(sfRenderWindow *window)
{
        sfRenderWindow_close(window);
}

void    manage_mouse_click(sfMouseButtonEvent event, coords_t coords, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    
    if (mouse.x <= coords.x + 68 && mouse.x >= coords.x && mouse.y <= coords.y + 100 && mouse.y >= coords.y)
        printf("touché\n");
}

void    analyse_events(sfRenderWindow *window, sfEvent event, coords_t coords)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        close_windows(window);

    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, coords, window);
}

sfSprite    *my_sprite_sheet_zombie(sfIntRect rect, coords_t coords)
{
    sfIntRect rect_zombie;
    sfSprite* zombie;
    sfTexture* zombie_texture;
    sfVector2f zombie_position = {coords.x, coords.y};

    rect_zombie.top = rect.top;
    rect_zombie.left = rect.left;
    rect_zombie.width = rect.width;
    rect_zombie.height = rect.height;
    zombie_texture = sfTexture_createFromFile("sprite/zombie_sheet.png", NULL);
    zombie = sfSprite_create();
    sfSprite_setTexture(zombie, zombie_texture, sfTrue);
    sfSprite_setTextureRect(zombie, rect_zombie);
    sfSprite_setPosition(zombie, zombie_position);
    return zombie;
}

sfSprite    *my_sprite_sheet_cursor(sfIntRect rect, sfRenderWindow *window)
{
    sfIntRect rect_cursor;
    sfSprite* cursor;
    sfTexture* cursor_texture;
    sfVector2f cursor_position;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    cursor_position.x = mouse.x - 77;
    cursor_position.y = mouse.y - 78;
    rect_cursor.top = 360;
    rect_cursor.left = 1025;
    rect_cursor.width = 200;
    rect_cursor.height = 200;
    cursor_texture = sfTexture_createFromFile("sprite/cursor.png", NULL);
    cursor = sfSprite_create();
    sfSprite_setTexture(cursor, cursor_texture, sfTrue);
    sfSprite_setTextureRect(cursor, rect_cursor);
    sfSprite_setPosition(cursor, cursor_position);
    return cursor;
}

sfSprite    *my_backgrd(sfRenderWindow *window)
{
    sfIntRect rect_backgrd;
    sfSprite* backgrd;
    sfTexture* backgrd_texture;
    sfVector2f backgrd_position;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    rect_backgrd.top = 0;
    rect_backgrd.left = 0;
    rect_backgrd.width = 1110;
    rect_backgrd.height = 600;
    backgrd_texture = sfTexture_createFromFile("sprite/backgd.png", NULL);
    backgrd = sfSprite_create();
    sfSprite_setTexture(backgrd, backgrd_texture, sfTrue);
    sfSprite_setTextureRect(backgrd, rect_backgrd);
    sfSprite_setPosition(backgrd, backgrd_position);
    return backgrd;
}

sfSprite    *move_rect(sfIntRect *rect, int offset, int max_value, coords_t coords)
{
    rect->top = 200;
    rect->left += offset;
    rect->width = 68;
    rect->height = 100;
    if (rect->left > max_value)
        rect->left = 544;

    return(my_sprite_sheet_zombie(*rect, coords));
}

sfSprite *my_clock(sfIntRect *rect, coords_t coords, clock_d clock)
{
    while (clock.second < 0.001)
    {
        clock.time = sfClock_getElapsedTime(clock.clock);
        clock.second = clock.time.microseconds/1000000.0;
    }
    sfClock_restart(clock.clock);
    return (move_rect(rect, 68, 1100, coords));
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
    sfRenderWindow_destroy(window);
}

void    draw_sprite(sfRenderWindow *window, sprite_t sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite.backgrd, NULL);
    sfRenderWindow_drawSprite(window, sprite.zombie, NULL);
    sfRenderWindow_drawSprite(window, sprite.cursor, NULL);
    sfRenderWindow_display(window);
}

void    Event(sfRenderWindow *window, sfEvent event, coords_t coords)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_events(window, event, coords);
    }
}

coords_t    reset_zombie(coords_t coords)
{
    if (coords.y == 442 && coords.x < 123) {
        coords.x = 1110;
        coords.y = coords.y - 165;
        //life();
    }
    if (coords.y == 277 && coords.x < 354){
        coords.x = 1110;
        coords.y = coords.y - 165;
        //life();
    }
    if (coords.y == 112 && coords.x < 639) {
        coords.x = 1110;
        coords.y = 442;
        //life();
    } else
        coords.x -= 20;
    return (coords);
}

int    line_random(void)
{
    int nbgen;
    srand(time(NULL));
    return nbgen=rand()%3+0;
}

int    line(int line)
{
    if (line == 0)
        return 442;
    if (line == 1)
        return 277;
    if (line == 2)
        return 112;
}

void    my_set_sprites(sprite_t *sprites, clock_d *clock, coords_t *coords, sfRenderWindow *window)
{
    clock->second = 0;
    coords->x = 1110;
    coords->y = line(line_random());
    sprites->backgrd = my_backgrd(window);
}

int    main(void)
{
    sfRenderWindow *window = windows();
    sfEvent event;
    sfIntRect rect_zombie;
    sfIntRect rect_cursor;
    sprite_t sprite;
    coords_t coords;
    clock_d Clock;

    rect_zombie.left = 0;
    my_set_sprites(&sprite, &Clock, &coords, window);
    Clock.clock = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        Event(window, event, coords);
        sprite.cursor = my_sprite_sheet_cursor(rect_cursor, window);
        sprite.zombie = my_clock(&rect_zombie, coords, Clock);
        draw_sprite(window, sprite);
        coords = reset_zombie(coords);
    }
    destroy_sprite(window, sprite);
    return 0;
}