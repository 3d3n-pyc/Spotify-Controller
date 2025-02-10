/*
** Spotify Controller, 2024
** File description:
** file
*/

#include <stdio.h>
#include <stdlib.h>

int cat_file(char *file)
{
    FILE *fp = fopen(file, "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL) {
        perror("fopen");
        return 84;
    }
    while (getline(&line, &len, fp) != -1) {
        printf("%s", line);
    }
    free(line);
    fclose(fp);
    return 0;
}