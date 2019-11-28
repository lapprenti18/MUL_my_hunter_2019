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
    sfFont* font;
    sfText* text;
    sfMusic* music_game;
    sfIntRect rect_heal;
    int statut;
    int volume;
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

/*typedef struct enum
{
    sfJoystickX,
    sfJoystickY,
    sfJoystickZ,
    sfJoystickR,
    sfJoystickU,
    sfJoystickV,
    sfJoystickPovX,
    sfJoystickPovY
    || sfJoystick_isButtonPressed(sfJoystickAxis, sfKeyA)
} sfJoystickAxis;*/