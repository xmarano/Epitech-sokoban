/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-leo.gregori
** File description:
** move_key.c
*/
#include "sokoban.h"

void if_move_left(sokoban_t *s)
{
    s->arr[s->p_y][s->p_x] = ' ';
    s->arr[s->p_y][s->p_x - 1] = 'P';
    s->arr[s->p_y][s->p_x - 2] = 'X';
}

void if_move_right(sokoban_t *s)
{
    s->arr[s->p_y][s->p_x] = ' ';
    s->arr[s->p_y][s->p_x + 1] = 'P';
    s->arr[s->p_y][s->p_x + 2] = 'X';
}
