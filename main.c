/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-leo.gregori
** File description:
** main.c
*/
#include "my.h"

static int format_h(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map  file representing the warehouse map, containing '#'");
    my_printf(" for walls,\n          'P' for the player, 'X' for boxes and ");
    my_printf("'0' for storage locations.\n");
    return 0;
}

int classic(char **argv, FILE *file)
{
    WINDOW *boite;
    int counter = 0;
    char c;

    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    c = getch();
    while (c != ' ') {
        clear();
        printw("%c - %dsec\n", c, counter);
        counter++;
        refresh();
        napms(1000);
        c = getch();
    }
    endwin();
    return 0;
}

int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1], "r");

    if (argc != 2) {
        write(2, "my_sokoban : Error argument\n", 29);
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        format_h();
        return 0;
    } else if (file != NULL) {
        classic(argv, file);
        return 0;
    } else {
        write(2, "my_sokoban : Error name or path file\n", 38);
        return 84;
    }
}
