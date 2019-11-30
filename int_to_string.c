/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** jsp.c
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

int    my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i = i + 1;
    }
    return (i);
}

void     my_swap(char *a, char *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

char     *my_revstr(char *str)
{
    int l = my_strlen(str)-1;
    int u = my_strlen(str);
    int d = 0;

    while (d < (u/2)) {
        my_swap(&str[l], &str[d]);
        l = l - 1;
        d = d + 1;
    }
    return (str);
}

char *int_to_string(int num)
{
    int i = 0;
    int rem;
    char *str = malloc(sizeof(char) * 2147483647);

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    while (num != 0)
    {
        rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num /= 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}