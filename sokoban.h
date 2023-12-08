/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-leo.gregori
** File description:
** my_sokoban : sokoban.h
*/
#include "my.h"
#ifndef SOKOBAN_H
    #define SOKOBAN_H
typedef struct s {
    struct stat info_file;
    int file_read;
    char *buffer;
    int bytes;
    int nb_line;
    char **arr;
    int nb_x;
    int nb_p;
    int nb_o;
    int nb_e;
    int p_x;
    int p_y;
    int pos_O_x;
    int pos_O_y;
    int check_O;
} sokoban_t;
void get_pos(sokoban_t *s);
void move_up(sokoban_t *s);
void move_down(sokoban_t *s);
void move_left(sokoban_t *s);
void move_right(sokoban_t *s);
char **map_in_map_clone(sokoban_t *s);
void display_map(sokoban_t *s);
#endif
