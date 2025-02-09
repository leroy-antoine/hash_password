/*
** EPITECH PROJECT, 2025
** hash_function.c
** File description:
** hash func
*/

#include <stddef.h>
#include "../include/my.h"
#include "../include/hashtable.h"

int hash(char *key, int len)
{
    int hash = 0;

    if (key == NULL)
        return ERROR;
    for (int i = 0; i < my_strlen(key); i++) {
        hash -= ((hash) ^ (key[i] << i)) + (hash >> 3);
        hash += ((key[i] * 31) + len) << 5;
        if (key[i] + len != 0)
            hash *= hash / (key[i] + len);
        hash -= key[i] >> 2;
    }
    if (hash < 0)
        hash *= -1;
    return hash;
}
