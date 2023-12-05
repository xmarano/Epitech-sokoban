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
    int i;
    int j;
    int k;
} sokoban_t;
#endif
