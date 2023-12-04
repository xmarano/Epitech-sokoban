/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-leo.gregori
** File description:
** main.c
*/
#include "my.h"

static void format_h(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map  file representing the warehouse map, containing '#'");
    my_printf(" for walls,\n          'P' for the player, 'X' for boxes and ");
    my_printf("'0' for storage locations.\n");
}

int sokoban(char **argv, FILE *file)
{
    WINDOW *boite;
    int taille = my_strlen(argv[1]);

    initscr();
    while (1) {
        clear();
        mvprintw(LINES / 2 , (COLS / 2) - (taille / 2), argv[1]);
        refresh();
        if (getch() == ' ')
            break;
    }
    endwin();
    return 0;
}

int info_line(char *buffer)
{
    int i = 0;
    int j = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            j++;
        i++;
    }
    return j;
}

int sokoban1(char **argv, FILE *file)
{
    WINDOW *boite;
    struct stat info_file;
    int stats = stat(argv[1], &info_file);
    int file_read = open(argv[1], O_RDONLY);
    char buffer[info_file.st_size];
    int bytes = read(file_read, buffer, sizeof(buffer));
    int nb_line = info_line(buffer);

    initscr();
    while (1) {
        clear();
        mvprintw(0, 0, buffer);
        refresh();
        if (getch() == ' ')
            break;
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
        sokoban1(argv, file);
        return 0;
    } else {
        write(2, "my_sokoban : Error name or path file\n", 38);
        return 84;
    }
}
