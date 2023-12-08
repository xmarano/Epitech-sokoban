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
    s->p_x = j;
    s->p_y = i;
}

int map_x(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i / 2;
}

static void key_pressed(sokoban_t *s, int *key)
{
    if (*key == 'A')
        move_up(s);
    if (*key == 'B')
        move_down(s);
    if (*key == 'C')
        move_right(s);
    if (*key == 'D')
        move_left(s);
    if (*key == ' ')
        s->arr = map_in_map_clone(s);
}

void check_0(sokoban_t *s, int i)
{
    for (int j = 0; s->arr[i][j]; j++) {
        if (s->arr[i][j] == 'O')
            s->check_O++;
    }
}

void display_while(sokoban_t *s, int *key)
{
    clear();
    for (int i = 0; s->nb_line > i; i++)
        mvprintw(LINES / 2 + i - s->nb_line,
        COLS / 2 - map_x(s->arr[i]), s->arr[i]);
    *key = getch();
    key_pressed(s, key);
    refresh();
    s->check_O = 0;
    for (int i = 0; s->arr[i] != NULL; i++)
        check_0(s, i);
}

void display_map(sokoban_t *s)
{
    WINDOW *boite;
    int key;
    char **map_po = map_in_map_clone(s);

    initscr();
    noecho();
    while (1) {
        display_while(s, &key);
        if (s->check_O == 0 && map_po[s->p_y][s->p_x - 1] != 'O'
        && map_po[s->p_y][s->p_x + 1] != 'O'
        && map_po[s->p_y + 1][s->p_x] != 'O'
        && map_po[s->p_y - 1][s->p_x] != 'O')
            break;
        if (key == 'q')
            break;
    }
    endwin();
}
