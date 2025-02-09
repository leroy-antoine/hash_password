/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** rompich
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i] != '\0')
        i += 1;
    return i;
}
