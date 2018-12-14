/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** my_strcmp.c
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (*s1 && s2 && s1[i] == s2[i]) {
        s1 = s1 + 1;
        s2 = s2 + 1;
    }
    return (*s1 - *s2);
}
