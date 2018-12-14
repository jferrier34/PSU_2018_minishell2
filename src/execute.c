/*
** EPITECH PROJECT, 2018
** execute.c
** File description:
** execute.c
*/

#include "../include/my.h"

char **split_path(char *s)
{
    int i;
    int len = my_strlen(s);
    char *t = s;

    for (i = 0; *s; s++)
        i += (*s == ':');
    char **ret = malloc(sizeof(char *) * (i + 2));
    int j;
    int k;
    for (j = 0; *t; t++) {
        ret[j] = malloc(len + 1);
        for (k = 0; *t && *t != ':'; t++) {
            ret[j][k] = *t;
            k++;
        }
        ret[j][k] = 0;
        j++;
    }
    ret[j] = NULL;
    return (ret);
}

char **get_path(env_var *env)
{
    env_var *tmp = env;
    //char **path = malloc(sizeof(char *) * 100);

    for (; tmp && my_strcmp(cut(tmp), "PATH"); tmp = tmp->next);
    if (!tmp)
        return (NULL);
    char *r = my_strdup(tmp->env + 5);
    return (split_path(r));
}

void execute(env_var *env, char **tab)
{
    char **path = get_path(env);
    int i;
    int status;
    for (i = 0; path[i] && access(sc(path[i], sc("/", tab[0])), X_OK)
        != 0; i++);
    if (path[i] == NULL)
        return;
    pid_t pid = fork();
    if (pid == 0) {
        execve(sc(path[i], sc("/", tab[0])), tab, NULL);
        exit(0);
    }
    else if (pid == -1)
        wait(&status);
}
