/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1
** File description:
** my_sokoban : my.h
*/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdarg.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#ifndef MY_H
    #define MY_H
int my_put_nbr(int nb);
int my_atoi(char *str);
char my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr_recursive(int nb);
int my_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
#endif
