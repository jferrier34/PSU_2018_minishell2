/*
** EPITECH PROJECT, 2018
** my_str_to_word_array2.c
** File description:
** my_str_to_word_array.c
*/

char **my_str_to_word_array2(char *argv)
{
    char **ret = malloc(sizeof(char *) * mal(argv));
    char **r = ret;
    char *save;
    for (; *argv; argv++){
	for (; *argv == 10; argv++);
	*ret = malloc(my_strlen(argv) + 1);
	save = *ret;
	for (; *argv && *argv != 10; argv++){
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


