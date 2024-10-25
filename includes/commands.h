/*
** Spotify Controller, 2024
** File description:
** commands header
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_

char *command_generator(const char *text, int state);
char **command_completion(const char *text, int start, int end);
void initialize_readline(void);
void add_history(const char *);

#endif /* COMMANDS_H_ */