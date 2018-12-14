/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr.c
*/

int my_getnbr(char *s)
{
    int res = 0;
    int neg = (-1) * ((*s) == '-');
    s += (neg == -1);

    for (; *s && *s <= '9' && *s >= '0'; s++) {
        res *= 10;
        res += (*s - 48);
    }
    if (neg == - 1)
        return (res * -1);
    return (res);
}
