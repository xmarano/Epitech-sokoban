/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-leo.gregori
** File description:
** main.c
*/
#include "sokoban.h"

static void format_h(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map  file representing the warehouse map, containing '#'");
    my_printf(" for walls,\n          'P' for the player, 'X' for boxes and ");
    my_printf("'0' for storage locations.\n");
}

static int info_line(char *buffer)
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

static int info_column(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i++;
    return i;
}

static void struct_sokoban(sokoban_t *s, char **argv)
{
    stat(argv[1], &s->info_file);
    s->file_read = open(argv[1], O_RDONLY);
    s->buffer = malloc(s->info_file.st_size * sizeof(char));
    s->bytes = read(s->file_read, s->buffer, s->info_file.st_size);
    s->nb_line = info_line(s->buffer);
    s->arr = malloc((s->nb_line + 1)* sizeof(char *));
    close(s->file_read);
    s->i = 0;
    s->j = 0;
    s->k = 0;
    s->nb_x = 0;
    s->nb_o = 0;
    s->nb_p = 0;
}

void map_in_arr(sokoban_t *s)
{
    while (s->buffer[s->k] != '\0') {
        s->arr[s->i] = malloc((info_column(s->buffer) + 1)* sizeof(char));
        while (s->buffer[s->k] != '\n') {
            s->arr[s->i][s->j] = s->buffer[s->k];
            s->j++;
            s->k++;
        }
        s->arr[s->i][s->j] = '\0';
        s->j = 0;
        s->i++;
        s->k++;
    }
    s->arr[s->i] = NULL;
}

void check_map(sokoban_t *s, int i, int j)
{
    if (s->arr[i][j] == 'P')
        s->nb_p++;
    if (s->arr[i][j] == 'X')
        s->nb_x++;
    if (s->arr[i][j] == 'O')
        s->nb_o++;
}

void display_map(sokoban_t *s)
{
    WINDOW *boite;

    initscr();
    while (1) {
        clear();
        for (int i = 0; s->nb_line > i; i++)
            mvprintw(LINES / 2 + i, COLS / 2, s->arr[i]);
        refresh();
        if (getch() == ' ')
            break;
    }
    endwin();
}

int sokoban1(char **argv, FILE *file)
{
    sokoban_t s;

    struct_sokoban(&s, argv);
    map_in_arr(&s);
    for (int i = 0; s.arr[i] != NULL; i++) {
        for (int j = 0; s.arr[i][j]; j++)
            check_map(&s, i, j);
    }
    if (s.nb_p != 1 || s.nb_o != s.nb_x)
        return 84;
    display_map(&s);
    return 0;
}

int main(int argc, char **argv)
{
    FILE *file = fopen(argv[1], "r");
    int return_nb;

    if (argc != 2) {
        write(2, "my_sokoban : Error argument\n", 29);
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0) {
        format_h();
        return 0;
    } else if (file != NULL) {
        return_nb = sokoban1(argv, file);
        return return_nb;
    } else {
        write(2, "my_sokoban : Error name or path file\n", 38);
        return 84;
    }
}
