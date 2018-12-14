/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/* structure of the project */

typedef struct s_env_var {
    char *env;
    struct s_env_var *next;
} env_var;

/* prototype about list functions */

env_var *my_put_in_list(char *env);

/* prototypes of the project */

char *sc(char *a, char *b);
char *cut(env_var *);
int cmp_env(char *env, char *cmp);
char *get_current_path(env_var *env);
//void move_dir(char **arg);
void move_dir(env_var *env, char *path);
void my_exit(char *value);
void my_parse_cmd(env_var *env, char **my_tab);
void my_env(env_var *envi);
env_var *init_env(char **env);
env_var *my_setenv(env_var *envi, char *env, char *);
env_var *my_unsetenv(env_var *envi, char *env);
void execute(env_var *env, char **tab);
//static void cd_root(void);

/* prototypes of my lib_functions */

void my_putchar(char c);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
int my_getnbr(char *s);
int my_put_nbr(int nb);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char const *src);
void my_putstr(char *str);
int is_chara(char c);
int coumpt(char const *str);
char **my_str_to_word_array(char *argv);

#endif
