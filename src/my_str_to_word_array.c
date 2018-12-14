/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <stddef.h>

char **my_str_to_word_array(char *argv)
{
    char **ret = malloc(sizeof(char *) * mal2(argv));
    char **r = ret;
    char *save;
    for (; *argv; argv++){
	for (; *argv == ' '; argv++);
	*ret = malloc(my_strlen(argv) + 1);
	save = *ret;
	for (; *argv && *argv != ' '; argv++){
	    **ret = *argv;
	    (*ret)++;
	}
	**ret = 0;
	*ret = save;
	ret++;
    }
    ret = NULL;
    return (r);
}
