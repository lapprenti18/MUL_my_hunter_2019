/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** high_score.c
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

int my_atoi(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}

void score_display(sprite_t *sprite)
{
    sfVector2f position = {0, 0};
    char *text = "\tHIGH SCORE\nEASY :\nMEDIUM :\nHARD :";

    sfText_setString(sprite->score_display, text);
    sfText_setFont(sprite->score_display, sprite->font_option_text);
    sfText_setCharacterSize(sprite->score_display, 30);
    sfText_setColor(sprite->score_display, sfBlue);
    sfText_setPosition(sprite->score_display, position);
}

void    display_hg_score(sprite_t *sprite)
{
    score_display(sprite);
    easy(sprite);
    medium(sprite);
    hard(sprite);
}

void    register_hg_score(sfRenderWindow *window, sprite_t *sprite)
{
    int fd;

    if (sprite->mode_of_the_game == 0) {
        if (sprite->score > sprite->hight_score_easy)
            fd = open("score_easy", O_WRONLY);
            write(fd, sprite->char_score, my_strlen(sprite->char_score));
            close(fd);
    }
    else if (sprite->mode_of_the_game == 1) {
        if (sprite->score > sprite->hight_score_medium)
            fd = open("score_medium", O_WRONLY);
            write(fd, sprite->char_score, my_strlen(sprite->char_score));
            close(fd);
    }
    else if (sprite->mode_of_the_game == 2) {
        if (sprite->score > sprite->hight_score_hard)
            fd = open("score_hard", O_WRONLY);
            write(fd, sprite->char_score, my_strlen(sprite->char_score));
            close(fd);
    }
}

void    display_score(sprite_t *sprite)
{
    sfVector2f score_position = {1070, 520};
    sfVector2f word_position = {950, 520};
    char *text = int_to_string(sprite->score);
    char *word = "score :";

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