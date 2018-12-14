/*
** EPITECH PROJECT, 2018
** mal.c
** File description:
** mal.c
*/

int mal(char *s)
{
    int p = 0;
    while (*s){
	p += (*s == 10);
	s++;
    }
    return (p + 2);
}
