/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-leo.gregori
** File description:
** in_game_key.c
*/
#include "sokoban.h"

void left_o(sokoban_t *s)
{
    char **map = map_in_map_clone(s);

    if (map[s->p_y][s->p_x] == 'O') {
        s->arr[s->p_y][s->p_x] = 'O';
    }
}

static void move_up2(sokoban_t *s)
{
    if (s->arr[s->p_y - 1][s->p_x] == 'O' ||
    s->arr[s->p_y - 1][s->p_x] == ' ') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y - 1][s->p_x] = 'P';
        left_o(s);
    }
    if (s->arr[s->p_y - 1][s->p_x] == 'X' &&
    s->arr[s->p_y - 2][s->p_x] == ' ') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y - 1][s->p_x] = 'P';
        s->arr[s->p_y - 2][s->p_x] = 'X';
        left_o(s);
    }
    if (s->arr[s->p_y - 2][s->p_x] == 'O' &&
    s->arr[s->p_y - 1][s->p_x] == 'X') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y - 1][s->p_x] = 'P';
        s->arr[s->p_y - 2][s->p_x] = 'X';
    }
}

void move_up(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->p_y - 2] == NULL)
        return;
    move_up2(s);
}

static void move_down2(sokoban_t *s)
{
    if (s->arr[s->p_y + 1][s->p_x] == 'O' ||
    s->arr[s->p_y + 1][s->p_x] == ' ') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y + 1][s->p_x] = 'P';
        left_o(s);
    }
    if (s->arr[s->p_y + 1][s->p_x] == 'X' &&
    s->arr[s->p_y + 2][s->p_x] == ' ') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y + 1][s->p_x] = 'P';
        s->arr[s->p_y + 2][s->p_x] = 'X';
        left_o(s);
    }
    if (s->arr[s->p_y + 2][s->p_x ] == 'O' &&
    s->arr[s->p_y + 1][s->p_x] == 'X') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y + 1][s->p_x ] = 'P';
        s->arr[s->p_y + 2][s->p_x ] = 'X';
    }
}

void move_down(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->p_y + 2] == NULL)
        return;
    move_down2(s);
}

void move_right(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->p_y][s->p_x + 1] == 'O' || s->arr[s->p_y][s->p_x + 1] == ' '
    && s->arr[s->p_y][s->p_x + 2] != '\0') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y][s->p_x + 1] = 'P';
        left_o(s);
    }
    if (s->arr[s->p_y][s->p_x + 1] == 'X' && s->arr[s->p_y][s->p_x + 2] == ' '
    && s->arr[s->p_y][s->p_x + 3] != '\0') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y][s->p_x + 1] = 'P';
        s->arr[s->p_y][s->p_x + 2] = 'X';
        left_o(s);
    }
    if (s->arr[s->p_y][s->p_x + 2] == 'O'
    && s->arr[s->p_y][s->p_x + 1] == 'X') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y][s->p_x + 1] = 'P';
        s->arr[s->p_y][s->p_x + 2] = 'X';
    }
}

void move_left(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->p_y][s->p_x - 1] == 'O' || s->arr[s->p_y][s->p_x - 1] == ' '
    && s->arr[s->p_y][s->p_x - 2] != '\0') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y][s->p_x - 1] = 'P';
        left_o(s);
    }
    if (s->arr[s->p_y][s->p_x - 1] == 'X' && s->arr[s->p_y][s->p_x - 2] == ' '
    && s->arr[s->p_y][s->p_x - 3] != '\0') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y][s->p_x - 1] = 'P';
        s->arr[s->p_y][s->p_x - 2] = 'X';
        left_o(s);
    }
    if (s->arr[s->p_y][s->p_x - 2] == 'O'
    && s->arr[s->p_y][s->p_x - 1] == 'X') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y][s->p_x - 1] = 'P';
        s->arr[s->p_y][s->p_x - 2] = 'X';
    }
}
