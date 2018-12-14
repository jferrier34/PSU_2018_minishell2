/*
** EPITECH PROJECT, 2018
** shell1_functions.c
** File description:
** shell1_functions.c
*/

#include "../include/my.h"

env_var *init_env(char **env)
{
    env_var *begin = my_put_in_list(env[0]);
    env_var *tmp = begin;
    int i = 1;

    while (env[i] != NULL) {
        tmp->next = my_put_in_list(env[i]);
        i++;
        tmp = tmp->next;
    }
    return (begin);
}

void my_env(env_var *envi)
{
    env_var *tmp = envi;
    while (tmp != NULL) {
        my_putstr(tmp->env);
        my_putstr("\n");
        tmp = tmp->next;
    }
}

char *sc(char *a, char *b)
{
    char *ret = malloc(my_strlen(a) + my_strlen(b) + 2);
    int i;

    for (i = 0; a[i]; i++)
        ret[i] = a[i];
    int j;
    for (j = 0; b[j]; j++) {
        ret[i] = b[j];
        i++;
    }
    ret[i] = 0;
    return (ret);
}

env_var *my_setenv(env_var *envi, char *env, char *value)
{
    env_var *tmp = envi;
    for (; tmp && my_strcmp(cut(tmp), env); tmp = tmp->next);
    char *new = malloc(my_strlen(env) + my_strlen(value) + 3);
    int i;
    for (i = 0; env[i] && env[i] != '='; i++)
        new[i] = env[i];
    new[i] = '=';
    i++;
    for (int j = 0; value && value[j]; j++) {
        if (my_strlen(value) != 0) {
        new[i] = value[j];
        i++;
        } else if (my_strlen(value) == 0){
            new[i] = env[i];
        }
    }
    new[i] = 0;
    if (tmp) {
        tmp->env = new;
        return envi;
    }
    for (tmp = envi; tmp->next; tmp = tmp->next);
    tmp->next = my_put_in_list(new);
    return (envi);
}

env_var *my_unsetenv(env_var *envi, char *env)
{
    if (my_strcmp(envi->env, env) == 0)
        envi = envi->next;
    else {
        env_var *tmp = envi;
        while (tmp->next && my_strcmp(cut(tmp->next), env))
            tmp = tmp->next;
        if (tmp->next)
            tmp->next = tmp->next->next;
    }
    return (envi);
}

char *cut(env_var *env)
{
    char *ret = malloc(my_strlen(env->env));
    int i;

    for (i = 0; env->env[i] != '='; i++)
        ret[i] = env->env[i];
    ret[i] = 0;
    return (ret);
}
