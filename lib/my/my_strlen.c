/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int nbr;
    if (!str)
        return (0);
    while (str[nbr] != '\0')
        nbr++;
    return (nbr);
}
