/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_hunter.h
*/

typedef struct my_hunter
{
    int x;
    int y;
}coords_t;

typedef struct sprite_c
{
    sfSprite* zombie;
    sfSprite* cursor;
    sfSprite* backgrd;
}sprite_t;

typedef struct clock_t
{
    sfClock *clock;
    sfTime time;
    float second;
}clock_d;

typedef struct all_struct
{
    coords_t coords_t;
    sprite_t sprite_t;
    clock_d clock_d;
}all_struct_t;

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