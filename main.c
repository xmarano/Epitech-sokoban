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
    s->nb_x = 0;
    s->nb_o = 0;
    s->nb_p = 0;
    s->nb_e = 0;
    s->p_x = 0;
    s->p_y = 0;
    s->pos_O_x = 0;
    s->pos_O_y = 0;
    s->check_O = 0;
}

void map_in_arr(sokoban_t *s)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (s->buffer[k] != '\0') {
        s->arr[i] = malloc((info_column(s->buffer) + 1)* sizeof(char));
        while (s->buffer[k] != '\n') {
            s->arr[i][j] = s->buffer[k];
            j++;
            k++;
        }
        s->arr[i][j] = '\0';
        j = 0;
        i++;
        k++;
    }
    s->arr[i] = NULL;
}

char **map_in_map_clone(sokoban_t *s)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **map_clone = malloc((s->nb_line + 1)* sizeof(char *));

    while (s->buffer[k] != '\0') {
        map_clone[i] = malloc((info_column(s->buffer) + 1)* sizeof(char));
        while (s->buffer[k] != '\n') {
            map_clone[i][j] = s->buffer[k];
            j++;
            k++;
        }
        map_clone[i][j] = '\0';
        j = 0;
        i++;
        k++;
    }
    map_clone[i] = NULL;
    return map_clone;
}

void check_map(sokoban_t *s, int i, int j)
{
    if (s->arr[i][j] == 'P')
        s->nb_p++;
    if (s->arr[i][j] == 'X')
        s->nb_x++;
    if (s->arr[i][j] == 'O')
        s->nb_o++;
    if (s->arr[i][j] != 'P' && s->arr[i][j] != 'O'
    && s->arr[i][j] != 'X' && s->arr[i][j] != '#' && s->arr[i][j] != ' ')
        s->nb_e++;
}

int sokoban(char **argv, FILE *file)
{
    sokoban_t s;

    struct_sokoban(&s, argv);
    map_in_arr(&s);
    for (int i = 0; s.arr[i] != NULL; i++) {
        for (int j = 0; s.arr[i][j]; j++)
            check_map(&s, i, j);
    }
    if (s.nb_p != 1 || s.nb_o != s.nb_x || s.nb_e != 0)
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
        return_nb = sokoban(argv, file);
        return return_nb;
    } else {
        write(2, "my_sokoban : Error name or path file\n", 38);
        return 84;
    }
}
