/*
** EPITECH PROJECT, 2018
** init_list.c
** File description:
** init_list.c
*/

#include "../include/my.h"

env_var *my_put_in_list(char *env)
{
    env_var *new = (env_var *)malloc(sizeof(env_var));
    new->env = malloc(sizeof(char) * my_strlen(env) + 1);
    int i = 0;

    while (env[i] != '\0') {
        new->env[i] = env[i];
        i++;
    }
    new->env[i] = 0;
    new->next = NULL;
    return (new);
}
