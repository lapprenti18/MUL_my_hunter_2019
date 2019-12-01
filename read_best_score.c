/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** read_best_score.c
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

void easy(sprite_t *sprite)
{
    char *filepath = "score_easy";
    char *buffer = malloc(sizeof(char) * 25000);
    struct stat file_info;
    int fd = 0;
    int read_bytes = 0;
    sfVector2f easy_position = {90, 33};

    fd = open(filepath, O_RDONLY);
    fstat(fd, &file_info);
    read(fd, buffer, file_info.st_size);
    buffer[file_info.st_size] = '\0';
    close(fd);
    sprite->hight_score_easy = my_atoi(buffer);
    sfText_setString(sprite->hg_score_easy, buffer);
    sfText_setFont(sprite->hg_score_easy, sprite->font_option_text);
    sfText_setCharacterSize(sprite->hg_score_easy, 30);
    sfText_setColor(sprite->hg_score_easy, sfBlue);
    sfText_setPosition(sprite->hg_score_easy, easy_position);
}

void medium(sprite_t *sprite)
{
    char *filepath = "score_medium";
    char *buffer = malloc(sizeof(char) * 25000);
    struct stat file_info;
    int fd = 0;
    int read_bytes = 0;
    sfVector2f medium_position = {110, 65};

    fd = open(filepath, O_RDONLY);
    fstat(fd, &file_info);
    read(fd, buffer, file_info.st_size);
    buffer[file_info.st_size] = '\0';
    close(fd);
    sprite->hight_score_medium = my_atoi(buffer);
    sfText_setString(sprite->hg_score_medium, buffer);
    sfText_setFont(sprite->hg_score_medium, sprite->font_option_text);
    sfText_setCharacterSize(sprite->hg_score_medium, 30);
    sfText_setColor(sprite->hg_score_medium, sfBlue);
    sfText_setPosition(sprite->hg_score_medium, medium_position);
}

void hard(sprite_t *sprite)
{
    char *filepath = "score_hard";
    char *buffer = malloc(sizeof(char) * 25000);
    struct stat file_info;
    int fd = 0;
    int read_bytes = 0;
    sfVector2f hard_position = {90, 95};

    fd = open(filepath, O_RDONLY);
    fstat(fd, &file_info);
    read(fd, buffer, file_info.st_size);
    buffer[file_info.st_size] = '\0';
    close(fd);
    sprite->hight_score_hard = my_atoi(buffer);
    sfText_setString(sprite->hg_score_hard, buffer);
    sfText_setFont(sprite->hg_score_hard, sprite->font_option_text);
    sfText_setCharacterSize(sprite->hg_score_hard, 30);
    sfText_setColor(sprite->hg_score_hard, sfBlue);
    sfText_setPosition(sprite->hg_score_hard, hard_position);
}