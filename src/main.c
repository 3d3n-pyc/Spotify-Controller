/*
** Spotify Controller, 2024
** File description:
** main
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
#include "../includes/get_data.h"
#include "../includes/utils.h"
#include "../includes/commands.h"

int check_play(char *str)
{
    if (!strncmp(str, "play", 4) == 0)
        return 0;
    send_instruction("org.mpris.MediaPlayer2.Player.Play");
    printf("\033[1;37mMusique lancée.\033[0m\n");
    return 1;
}

int check_pause(char *str)
{
    if (!strncmp(str, "pause", 5) == 0)
        return 0;
    send_instruction("org.mpris.MediaPlayer2.Player.Pause");
    printf("\033[1;37mMusique mise en pause.\033[0m\n");
    return 1;
}

int check_next(char *str)
{
    if (!strncmp(str, "next", 4) == 0)
        return 0;
    send_instruction("org.mpris.MediaPlayer2.Player.Next");
    printf("\033[1;37mPassage à la musique suivante.\033[0m\n");
    return 1;
}

int check_prev(char *str)
{
    if (!strncmp(str, "prev", 4) == 0)
        return 0;
    send_instruction("org.mpris.MediaPlayer2.Player.Previous");
    printf("\033[1;37mPassage à la musique précédente.\033[0m\n");
    return 1;
}

int check_current(char *str)
{
    if (!strncmp(str, "current", 8) == 0)
        return 0;
    printf("\033[1;37mEn train de jouer \033[1;32m%s \033[1;37mpar \033[1;32m%s \033[0;37m(%s)\033[1;37m.\n", get_current_song(), get_current_artist(), get_current_length());
    return 1;
}

int check(char *str)
{
    if (check_play(str) == 1)
        return 0;
    if (check_pause(str) == 1)
        return 0;
    if (check_next(str) == 1)
        return 0;
    if (check_prev(str) == 1)
        return 0;
    if (check_current(str) == 1)
        return 0;
    if (strncmp(str, "exit", 4) == 0)
        return -1;
    return 84;
}

int main(int ac, char **av) {
    char *input;
    int result = 0;

    initialize_readline();

    while ((input = readline("\033[0mspotify> ")) != NULL) {
        if (strlen(input) > 0) {
            add_history(input);
            result = check(input);
            if (result == 84)
                printf("\033[0;31mAvailable commands: play, pause, next, prev, current.\033[0m\n");
            if (result == -1)
                break;
        }
        free(input);
    }

    return 0;
}