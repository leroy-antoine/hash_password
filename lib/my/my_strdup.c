/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** task 01 day 08
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    if (src == NULL)
        return NULL;
    i = my_strlen(src);
    dest = malloc(sizeof(char) * (i + 1));
    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}
