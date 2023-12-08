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

static void first_while(sokoban_t *s, int *i, int *j, int *nb_x)
{
    while (s->arr[*i][*j] != '\0') {
        if (s->arr[*i][*j] == 'X')
            (*nb_x)++;
        (*j)++;
    }
    *j = 0;
    (*i)++;
}

static void second_while(sokoban_t *s, int *i, int *j, int *x)
{
    if (s->arr[*i][*j] == 'X') {
        if (s->arr[(*i) - 1][*j] == '#' && s->arr[(*i)][(*j) + 1] == '#')
            (*x)++;
        if (s->arr[(*i) - 1][(*j)] == '#' && s->arr[(*i)][(*j) - 1] == '#')
            (*x)++;
        if (s->arr[(*i) + 1][(*j)] == '#' && s->arr[(*i)][(*j) + 1] == '#')
            (*x)++;
        if (s->arr[(*i) + 1][(*j)] == '#' && s->arr[(*i)][(*j) - 1] == '#')
            (*x)++;
    }
    (*j)++;
}

static void loose_x(sokoban_t *s)
{
    int i = 0;
    int j = 0;
    int nb_x = 0;
    int x = 0;

    while (s->arr[i] != NULL)
        first_while(s, &i, &j, &nb_x);
    i = 0;
    j = 0;
    while (s->arr[i] != NULL) {
        while (s->arr[i][j] != '\0')
            second_while(s, &i, &j, &x);
        j = 0;
        i++;
    }
    if (nb_x == x)
        exit(1);
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
        loose_x(s);
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
    if (s->p_y - 2 < 0)
        return;
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
        loose_x(s);
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
        if_move_right(s);
        left_o(s);
        loose_x(s);
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
        if_move_left(s);
        left_o(s);
        loose_x(s);
    }
    if (s->arr[s->p_y][s->p_x - 2] == 'O'
    && s->arr[s->p_y][s->p_x - 1] == 'X') {
        s->arr[s->p_y][s->p_x] = ' ';
        s->arr[s->p_y][s->p_x - 1] = 'P';
        s->arr[s->p_y][s->p_x - 2] = 'X';
    }
}
