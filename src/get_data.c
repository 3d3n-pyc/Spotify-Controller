/*
** Spotify Controller, 2024
** File description:
** get_data
*/

#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *get_current_length(void)
{
    char *base = "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.freedesktop.DBus.Properties.Get string:org.mpris.MediaPlayer2.Player string:Metadata | sed -n '/length/{n;p}' | cut -d '\"' -f 2";
    FILE *fp;
    char path[1035];
    char *result = malloc(1035);
    char *time_str;
    char *uint64_pos;

    if (result == NULL)
        return NULL;
    result[0] = '\0';
    fp = popen(base, "r");
    if (fp == NULL) {
        free(result);
        return NULL;
    }
    for (; fgets(path, sizeof(path)-1, fp) != NULL; strcat(result, path));
    uint64_pos = strstr(result, "uint64");
    if (uint64_pos == NULL) {
        free(result);
        return NULL;
    }
    uint64_pos += 7;
    pclose(fp);
    uint64_pos[strlen(uint64_pos) - 1] = '\0';
    time_str = time_to_str(str_to_nbr(uint64_pos) / 1000000);
    free(result);
    return time_str;
}

char *get_current_song(void)
{
    char *base = "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.freedesktop.DBus.Properties.Get string:org.mpris.MediaPlayer2.Player string:Metadata | sed -n '/title/{n;p}' | cut -d '\"' -f 2";
    FILE *fp;
    char path[1035];
    char *result = malloc(1035);

    if (result == NULL)
        return "UNKNOWN";
    result[0] = '\0';
    fp = popen(base, "r");
    if (fp == NULL) {
        free(result);
        return "UNKNOWN";
    }
    for (; fgets(path, sizeof(path)-1, fp) != NULL; strcat(result, path));
    pclose(fp);
    result[strlen(result) - 1] = '\0';
    return result;
}

char *get_current_artist(void)
{
    char *base = "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.freedesktop.DBus.Properties.Get string:org.mpris.MediaPlayer2.Player string:Metadata | sed -n '/artist/{n;n;p}' | cut -d '\"' -f 2";
    FILE *fp;
    char path[1035];
    char *result = malloc(1035);

    if (result == NULL)
        return "UNKNOWN";
    result[0] = '\0';
    fp = popen(base, "r");
    if (fp == NULL) {
        free(result);
        return "UNKNOWN";
    }
    for (; fgets(path, sizeof(path)-1, fp) != NULL; strcat(result, path));
    pclose(fp);
    result[strlen(result) - 1] = '\0';
    return result;
}
