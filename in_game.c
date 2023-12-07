/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-leo.gregori
** File description:
** in_game.c
*/
#include "sokoban.h"

void get_pos(sokoban_t *s)
{
    int i = 0;
    int j = 0;

    while (s->arr[i][j] != 'P') {
        j++;
        if (s->arr[i][j] == '\0') {
            j = 0;
            i++;
        }
    }
    s->pos_p_x = j;
    s->pos_p_y = i;
}

static void move_up(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->pos_p_y - 1][s->pos_p_x] == ' '
    && s->arr[s->pos_p_y - 2] != NULL) {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y - 1][s->pos_p_x] = 'P';
    }
    if (s->arr[s->pos_p_y - 1][s->pos_p_x] == 'X'
    && s->arr[s->pos_p_y - 2][s->pos_p_x] == ' '
    && s->arr[s->pos_p_y - 3] != NULL) {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y - 1][s->pos_p_x] = 'P';
        s->arr[s->pos_p_y - 2][s->pos_p_x] = 'X';
    }
}

static void move_down(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->pos_p_y + 1][s->pos_p_x] == ' '
    && s->arr[s->pos_p_y + 2] != NULL) {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y + 1][s->pos_p_x] = 'P';
    }
    if (s->arr[s->pos_p_y + 1][s->pos_p_x] == 'X'
    && s->arr[s->pos_p_y + 2][s->pos_p_x] == ' '
    && s->arr[s->pos_p_y + 3] != NULL) {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y + 1][s->pos_p_x] = 'P';
        s->arr[s->pos_p_y + 2][s->pos_p_x] = 'X';
    }
}

static void move_right(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->pos_p_y][s->pos_p_x + 1] == ' '
    && s->arr[s->pos_p_y][s->pos_p_x + 2] != '\0') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y][s->pos_p_x + 1] = 'P';
    }
    if (s->arr[s->pos_p_y][s->pos_p_x + 1] == 'X'
    && s->arr[s->pos_p_y][s->pos_p_x + 2] == ' '
    && s->arr[s->pos_p_y][s->pos_p_x + 3] != '\0') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y][s->pos_p_x + 1] = 'P';
        s->arr[s->pos_p_y][s->pos_p_x + 2] = 'X';
    }
}

static void move_left(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->pos_p_y][s->pos_p_x - 1] == ' '
    && s->arr[s->pos_p_y][s->pos_p_x - 2] != '\0') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y][s->pos_p_x - 1] = 'P';
    }
    if (s->arr[s->pos_p_y][s->pos_p_x - 1] == 'X'
    && s->arr[s->pos_p_y][s->pos_p_x - 2] == ' '
    && s->arr[s->pos_p_y][s->pos_p_x - 3] != '\0') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y][s->pos_p_x - 1] = 'P';
        s->arr[s->pos_p_y][s->pos_p_x - 2] = 'X';
    }
    if (s->arr[s->pos_p_y][s->pos_p_x - 1] == 'O') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y][s->pos_p_x - 1] = 'P';
        s->arr[s->pos_p_y][s->pos_p_x - 2] = 'X';
    }
}

int map_x(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i / 2;
}

void key_pressed(sokoban_t *s, int key)
{
    if (key == 'A')
        move_up(s);
    if (key == 'B')
        move_down(s);
    if (key == 'C')
        move_right(s);
    if (key == 'D')
        move_left(s);
    if (key == ' ')
        s->arr = map_in_map_clone(s);
}

void display_map(sokoban_t *s)
{
    WINDOW *boite;
    int key;

    initscr();
    noecho();
    while (1) {
        clear();
        for (int i = 0; s->nb_line > i; i++)
            mvprintw(LINES / 2 + i - s->nb_line,
            COLS / 2 - map_x(s->arr[i]), s->arr[i]);
        key = getch();
        key_pressed(s, key);
        refresh();
        if (key == 'q')
            break;
    }
    endwin();
}
