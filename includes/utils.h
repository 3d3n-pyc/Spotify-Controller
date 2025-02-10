/*
** Spotify Controller, 2024
** File description:
** utils header
*/

#ifndef UTILS_H_
    #define UTILS_H_

int cat_file(char *file);
char *time_to_str(int time);
int str_to_nbr(char *str);
char *concat_three(const char *s1, const char *s2, const char *s3);
int send_instruction(char *instruction);

#endif /* UTILS_H_ */
