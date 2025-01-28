/*
** Spotify Controller, 2024
** File description:
** utils
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int str_to_nbr(char *str)
{
    int result = 0;

    if (str == NULL)
        return -1;
    for (; *str; str++) {
        if (*str < '0' || *str > '9')
            return -1;
        result = result * 10 + *str - '0';
    }
    return result;
}

char *concat_three(const char *s1, const char *s2, const char *s3)
{
    char *result = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1);

    if (result == NULL)
        return NULL;
    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);
    return result;
}

char *num_to_str(int nbr)
{
    int mult = 1;
    int i = 0;
    char *str = malloc(sizeof(char) * 10);

    if (str == NULL)
        return NULL;
    for (;(nbr / mult) >= 10; mult *= 10);
    for (; mult > 0; mult /= 10) {
        str[i] = '0' + (nbr / mult) % 10;
        nbr %= mult;
        i++;
    }
    str[i] = '\0';
    return str;
}

char *time_to_str(int time)
{
    int seconds = time % 60;
    int minutes = (time / 60) % 60;
    char *seconds_str;
    char *minutes_str;
    char *temp;
    char *result;

    seconds_str = num_to_str(seconds);
    minutes_str = num_to_str(minutes);
    if (strlen(seconds_str) == 1) {
        temp = concat_three("0", seconds_str, "");
        free(seconds_str);
        seconds_str = temp;
    }
    result = concat_three(minutes_str, ":", seconds_str);
    free(seconds_str);
    free(minutes_str);
    return result;
}

int send_instruction(char *instruction)
{
    char *base = "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 ";
    char *redirect = " > /dev/null 2>&1";
    char *command = concat_three(base, instruction, redirect);

    if (command == NULL)
        return 84;
    system(command);
    return 0;
}