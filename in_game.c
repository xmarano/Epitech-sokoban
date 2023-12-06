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
    if (s->arr[s->pos_p_y - 1][s->pos_p_x] != '#') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y - 1][s->pos_p_x] = 'P';
    }
}

static void move_down(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->pos_p_y + 1][s->pos_p_x] != '#') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y + 1][s->pos_p_x] = 'P';
    }
}

static void move_right(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->pos_p_y][s->pos_p_x + 1] != '#') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y][s->pos_p_x + 1] = 'P';
    }
}

static void move_left(sokoban_t *s)
{
    get_pos(s);
    if (s->arr[s->pos_p_y][s->pos_p_x - 1] != '#') {
        s->arr[s->pos_p_y][s->pos_p_x] = ' ';
        s->arr[s->pos_p_y][s->pos_p_x - 1] = 'P';
    }
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
}

void display_map(sokoban_t *s)
{
    WINDOW *boite;
    int key;

    initscr();
    while (1) {
        clear();
        for (int i = 0; s->nb_line > i; i++)
            mvprintw(LINES / 2 + i, COLS / 2, s->arr[i]);
        key = getch();
        key_pressed(s, key);
        refresh();
        if (key == 'q')
            break;
    }
    endwin();
}
