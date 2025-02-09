/*
** EPITECH PROJECT, 2024
** convert_base.c
** File description:
** convert any number to any base
*/
#include "../include/my.h"
#include <stdlib.h>

char *convert_base(unsigned long nb, int base)
{
    char *num = malloc(sizeof(char) * 10);
    long temp = 0;
    int i = 0;

    while (nb != 0) {
        temp = nb % base;
        if (temp < 10)
            temp += 48;
        else
            temp += 55;
        num[i] = temp;
        nb = nb / base;
        i += 1;
    }
    my_revstr(num);
    return num;
}
