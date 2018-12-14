/*
** EPITECH PROJECT, 2018
** mal2.c
** File description:
** mal2.c
*/

int mal2(char *s)
{
    int p = 0;
    while (*s){
	p += (*s == 10);
	s++;
    }
    return (p + 2);
}

