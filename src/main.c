/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

//int main(int ac, char **av, char **env)

char **my_str_to_word_array2(char *str);

int main(int ac, char **av, char **env)
{
    char **cmd;
    char **my_tab;
    char *buffer = malloc(sizeof(char) * 1024);
    int i;
    av += ac;
    if (!env || env[0] == NULL)
        return (0);
    env_var *e = init_env(env);
    while (1) {
	if (isatty(0))
	    my_putstr("$>");
        i = read(0, buffer, 1024);
        if (i == 0) {
            return (0);
        }
        buffer[i] = 0;
        cmd = my_str_to_word_array2(buffer);
        for (; *cmd && **cmd; cmd++) {
	    if (!isatty(0)){
		my_putstr("$>");
		my_putstr(*cmd);
	    }
	    my_tab = my_str_to_word_array(*cmd);
	    my_parse_cmd(e, my_tab);
        }
    }
}
