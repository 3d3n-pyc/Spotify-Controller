/*
** Spotify Controller, 2024
** File description:
** commands
*/

#include <readline/readline.h>
#include <readline/history.h>

char *commands[] = {
    "play",
    "pause",
    "next",
    "prev",
    "current",
    "exit",
    NULL
};

char *command_generator(const char *text, int state) {
    static int list_index, len;
    char *name;

    if (!state) {
        list_index = 0;
        len = strlen(text);
    }

    while ((name = commands[list_index++])) {
        if (strncmp(name, text, len) == 0) {
            return strdup(name);
        }
    }

    return NULL;
}

char **command_completion(const char *text, int start, int end) {
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, command_generator);
}

void initialize_readline(void) {
    rl_attempted_completion_function = command_completion;
}
