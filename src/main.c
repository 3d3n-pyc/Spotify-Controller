/*
** Spotify Controller, 2024
** File description:
** main
*/

#include "get_data.h"
#include "utils.h"
#include "commands.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <readline/readline.h>

static int check_play(char *str)
{
    if (!strncmp(str, "play", 4) == 0)
        return 0;
    send_instruction("org.mpris.MediaPlayer2.Player.Play");
    printf("\033[1;37mMusique lancée.\033[0m\n");
    return 1;
}

static int check_pause(char *str)
{
    if (!strncmp(str, "pause", 5) == 0)
        return 0;
    send_instruction("org.mpris.MediaPlayer2.Player.Pause");
    printf("\033[1;37mMusique mise en pause.\033[0m\n");
    return 1;
}

static int check_next(char *str)
{
    if (!strncmp(str, "next", 4) == 0)
        return 0;
    send_instruction("org.mpris.MediaPlayer2.Player.Next");
    printf("\033[1;37mPassage à la musique suivante.\033[0m\n");
    return 1;
}

static int check_prev(char *str)
{
    if (!strncmp(str, "prev", 4) == 0)
        return 0;
    send_instruction("org.mpris.MediaPlayer2.Player.Previous");
    printf("\033[1;37mPassage à la musique précédente.\033[0m\n");
    return 1;
}

static int check_current(char *str)
{
    char *song;
    char *artist;
    char *length;

    if (!strncmp(str, "current", 7) == 0)
        return 0;
    song = get_current_song();
    artist = get_current_artist();
    length = get_current_length();
    printf("\033[1;37mEn train de jouer \033[1;32m%s \033[1;37mpar \033[1;32m%s \033[0;37m(%s)\033[1;37m.\n", song, artist, length);
    free(song);
    free(artist);
    free(length);
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

int terminal(void)
{
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
    free(input);
    rl_cleanup_after_signal();
    rl_clear_history();
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return terminal();
    for (int i = 1; i < ac; i++) {
        if (check(av[i]) == 84)
            return 84;
    }
}
